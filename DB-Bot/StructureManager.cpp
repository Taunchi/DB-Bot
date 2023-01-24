#include "StructureManager.h"
#include <random>
#include <iterator>


StructureManager::StructureManager(std::shared_ptr<WordManager> dictionary)
{
	this->dictionary = dictionary;
    LoadGrammarArray();
	LoadStructures();
}

//TESTING METHOD 8/7/2022
void StructureManager::speakRandom()
{
    std::random_device rd;     // Only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(0, sentenceStructures.size()); // Guaranteed unbiased

    auto randNum = uni(rng);
    if (randNum >= sentenceStructures.size() && sentenceStructures.size() != 0) { randNum -= 1; }
    else if (randNum < 0) { randNum += 1; }
	//int randNum = rand() % (sentenceStructures.size() - 1 + 1) + 0;
    std::string blah;
    try {
        auto item = sentenceStructures.begin();
        std::advance(item, randNum);
        blah = item->second->getSentence();
        //auto random_it = std::next(std::begin(sentenceStructures), randNum);
        //blah = random_it->second->getSentence();
    }
    catch (_exception e) {
        std::cout << e.name;
    }
    try {
        std::cout << blah;
    }
    catch (const std::invalid_argument& ia) {
        std::cout << ia.what();
    }
}

//TODO fix this in the follows method? why are they all pronouns? 8/16/2022
//TESTING METHOD TO GENERATE SENTENCES 8/7/2022
void StructureManager::generateSentence()
{
	//TODO READD BREAK POINTS HERE
    int prevTypeNum = 0;
    bool follows = false;

    std::random_device rd;     // Only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(1, sentenceStructures.size() - 1); // Guaranteed unbiased
    auto randNum = uni(rng);
	//int randNum = rand() % (sentenceStructures.size() - 1 + 1) + 0;
	auto random_it = std::next(std::begin(sentenceStructures), randNum);
	random_it->second->getSentence();

    for (auto testword : random_it->second->getWords())
    {
        if (testword->getType() == "")
        {
            testword->setType("NoType", true);
        }
    }

	auto tempStruc = random_it->second->getStructure();
	auto tempwords = tempStruc->getWords();
	std::string tempString = "\n ";
	    for (auto word: tempwords)
		{
            follows = false;
            std::string type = "";
            int typeNum = 0;
            type = word->getType();
            if (type == "noun") { typeNum = 0; }
            else if (type == "pronoun") { typeNum = 1; }
            else if (type == "verb") { typeNum = 2; }
            else if (type == "adverb") { typeNum = 3; }
            else if (type == "adjective") { typeNum = 4; }
            else if (type == "preposition") { typeNum = 5; }
            else if (type == "conjunction") { typeNum = 6; }
            else if (type == "determiner") { typeNum = 7; }
            else if (type == "interjection") { typeNum = 8; }
            else if (type == "exclamation") { typeNum = 9; }
            else if (type == "auxiliary") { typeNum = 11; }
            else if (type == "article") { typeNum = 12; }
            else if (type == "punctuation") { typeNum = 13; }
            else if (type == "NoType") { typeNum = 10; }
            else {
                word->setType("NoType", true);
                typeNum = 10;
            }
            std::string tempword;
            std::string prevword;
            //TODO PUT BREAK HERE
            //TODO 8/9/2022 ADD CASE 9 conjunctions and exclamation
            prevword = word->getName();
            tempword = dictionary->getRandomWord(type)->getName();
            //TODO PUT BREAK HERE
            while (!follows) {
                follows = this->grammar[prevTypeNum][typeNum];
                auto testword = dictionary->getRandomWord(type);
                tempword = testword->getName();
                while (tempword == prevword)
                {
                    testword = dictionary->getRandomWord(type);
                    tempword = testword->getName();
                    //std::cout << tempword + " word and type " + type + " Word of type " + testword->getType();
                    
                    follows = this->grammar[prevTypeNum][typeNum];
                }
                this->grammar[prevTypeNum][typeNum] = true;
                // ADJUST TODO 8/11/2022 for grammar

                follows = this->grammar[prevTypeNum][typeNum];

            }
            //TODO PUT BREAK HERE
            //std::cout << tempword + " THIS IS TEMPWORD AFTER FOLLOW TRUE";
            tempString += tempword + " ";
            //std::cout << tempString + " so far ";
            prevword = tempword;
            prevTypeNum = typeNum;
            follows = false;
		}
	tempString += ".\n ";
	addSentenceNode(tempString);
	std::cout << tempString + " This is generated.";

}

// add sentence structrure to structural map
void StructureManager::addSentence(std::shared_ptr<SentenceStructure> ss)
{
	// 8/7/2022 *createSentenceNode(ss)
	sentenceStructures.at(ss->strucHash()) = createSentenceNode(ss);
}

// add sentence node to structural map
void StructureManager::addSentenceNode(std::shared_ptr<SentencePoint> sp)
{
	// 8/7/2022 *sp
	sentenceStructures.at(sp->getStructure()->strucHash()) = sp;
}

// create and add sentence node from sentence string
void StructureManager::addSentenceNode(std::string sentence)
{
	//New testting 8/7/2022
	std::shared_ptr<SentencePoint> sp = createSentenceNode(sentence);
	auto stringsp = sp->getSentence();
	sentenceStructures.insert(std::make_pair(stringsp, sp));
	sp->getStructure()->strucHash();
	if (sentenceStructures.find(stringsp) != sentenceStructures.end())
	{
		// 8/7/2022 *sp
		sentenceStructures.at(stringsp) = sp;
	}
	else
	{
		//sentenceStructures.at(sp->getStructure()->strucHash())->setStructure(sp->getStructure());
		// testing sentence output
		std::cout << "Out of Range in StructureManager->addSentenceNode > " + sp->getSentence() + " < ";
	}
}

// create sentence structure node from sentence string
std::shared_ptr<SentencePoint> StructureManager::createSentenceNode(std::string sentence)
{
	//8/7/2022 testing
	std::unique_ptr<SentencePoint> sp = std::make_unique<SentencePoint>();
	auto testing = std::make_shared<SentenceStructure>(getWords(sentence));
	sp->setStructure(testing);
	return sp;
}

// create sentence structure node from sentence structure
std::shared_ptr<SentencePoint> StructureManager::createSentenceNode(std::shared_ptr<SentenceStructure> sentence)
{
	std::unique_ptr<SentencePoint> sp = std::make_unique<SentencePoint>();
	sp->setStructure(std::make_shared<SentenceStructure>(sentence->getWords()));
	return sp;
}

//TODO 8/11/2022 CHANGE SET TYPE TO ACCOUNT FOR SENTENCE STRUCTURE add types 
// create shared_ptr vector of word objects from dictionary using sentence string
std::vector<std::shared_ptr<Word>> StructureManager::getWords(std::string sentence)
{
	std::string temp;
	std::vector<std::shared_ptr<Word>> words;
	for (auto c : sentence)
	{
		if (c != ' ')
		{
			if (c == '?' || c == '!' || c == '.' || c == ',') { words.push_back(dictionary->getWord(temp)); temp = c; words.push_back(dictionary->getWord(temp)); temp = ""; }
			else { temp += std::tolower(c); }

		}
		else { words.push_back(dictionary->getWord(temp)); temp = ""; }
	}

	return words;
}

// load booleans into grammatical structure array
// 1 noun, 2 pronoun, 3 verb, 4 adverb, 5 adjective, 6 preposition, 7 conjunction, 8 determiner, 9 interjection, 10 exclamation, 11 notype, 12 auxiliary
void StructureManager::LoadGrammarArray()
{
    bool follows = false;
        for (int i = 0; i < 14; i++)
        {
            // 1 noun, 2 pronoun, 3 verb, 4 adverb, 5 adjective, 6 preposition, 7 conjunction, 8 determiner, 9 interjection, 10 exclamation, 11 notype, 12 auxiliary
            for (int e = 0; e < 14; e++)
            {
                //std::cout << " This is where we're at in grammar array " + std::to_string(i) + " and " + std::to_string(e);
                switch (i)
                {
                    case 0: // noun // noun
                        switch (e) {
                            case 0: // noun
                                follows = false;
                                break;
                            case 1: // pronoun
                                follows = false;
                                break;
                            case 2: // verb
                                follows = true;
                                break;
                            case 3: // adverb
                                follows = true;
                                break;
                            case 4: // adjective
                                follows = true;
                                break;
                            case 5: // preposition
                                follows = false;
                                break;
                            case 6: // conjunction
                                follows = true;
                                break;
                            case 7: // determiner
                                follows = true;
                                break;
                            case 8: // interjection
                                follows = true;
                                break;
                            case 9: // exclamation
                                follows = true;
                                break;
                            case 10: //NoType
                                follows = true;
                                break;
                            case 11: // auxiliary
                                follows = true;
                                break;
                            case 12: // article
                                follows = false;
                                break;
                            case 13: // punctuation
                                follows = true;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 1: // pronoun //pronoun
                        switch (e) {
                            case 0: // noun
                                follows = false;
                                break;
                            case 1: // pronoun
                                follows = false;
                                break;
                            case 2: // verb
                                follows = true;
                                break;
                            case 3: // adverb
                                follows = false;
                                break;
                            case 4: // adjective
                                follows = true;
                                break;
                            case 5: // preposition
                                follows = true;
                                break;
                            case 6: // conjunction
                                follows = true;
                                break;
                            case 7: // determiner
                                follows = false;
                                break;
                            case 8: // interjection
                                follows = true;
                                break;
                            case 9: // exclamation
                                follows = true;
                                break;
                            case 10: //NoType
                                follows = true;
                                break;
                            case 11: // auxiliary
                                follows = true;
                                break;
                            case 12: // article
                                follows = false;
                                break;
                            case 13: // punctuation
                                follows = true;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 2: // verb // verb
                        switch (e) {
                            case 0: // noun
                                follows = true;
                                break;
                            case 1: // pronoun
                                follows = true;
                                break;
                            case 2: // verb
                                follows = false;
                                break;
                            case 3: // adverb
                                follows = true;
                                break;
                            case 4: // adjective
                                follows = false;
                                break;
                            case 5: // preposition
                                follows = false;
                                break;
                            case 6: // conjunction
                                follows = false;
                                break;
                            case 7: // determiner
                                follows = false;
                                break;
                            case 8: // interjection
                                follows = true;
                                break;
                            case 9: // exclamation
                                follows = true;
                                break;
                            case 10: //NoType
                                follows = true;
                                break;
                            case 11: // auxiliary
                                follows = true;
                                break;
                            case 12: // article
                                follows = false;
                                break;
                            case 13: // punctuation
                                follows = true;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 3: // adverb //adverb
                        switch (e) {
                            case 0: // noun
                                follows = false;
                                break;
                            case 1: // pronoun
                                follows = true;
                                break;
                            case 2: // verb
                                follows = true;
                                break;
                            case 3: // adverb
                                follows = false;
                                break;
                            case 4: // adjective
                                follows = true;
                                break;
                            case 5: // preposition
                                follows = false;
                                break;
                            case 6: // conjunction
                                follows = true;
                                break;
                            case 7: // determiner
                                follows = false;
                                break;
                            case 8: // interjection
                                follows = true;
                                break;
                            case 9: // exclamation
                                follows = true;
                                break;
                            case 10: //NoType
                                follows = true;
                                break;
                            case 11: // auxiliary
                                follows = true;
                                break;
                            case 12: // article
                                follows = false;
                                break;
                            case 13: // punctuation
                                follows = true;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 4: // adjective //adjective
                        switch (e) {
                            case 0: // noun
                                follows = false;
                                break;
                            case 1: // pronoun
                                follows = false;
                                break;
                            case 2: // verb
                                follows = true;
                                break;
                            case 3: // adverb
                                follows = false;
                                break;
                            case 4: // adjective
                                follows = false;
                                break;
                            case 5: // preposition
                                follows = false;
                                break;
                            case 6: // conjunction
                                follows = true;
                                break;
                            case 7: // determiner
                                follows = true;
                                break;
                            case 8: // interjection
                                follows = true;
                                break;
                            case 9: // exclamation
                                follows = true;
                                break;
                            case 10: //NoType
                                follows = true;
                                break;
                            case 11: // auxiliary
                                follows = true;
                                break;
                            case 12: // article
                                follows = false;
                                break;
                            case 13: // punctuation
                                follows = true;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 5: // preposition //preposition
                        switch (e) {
                            case 0: // noun
                                follows = true;
                                break;
                            case 1: // pronoun
                                follows = false;
                                break;
                            case 2: // verb
                                follows = true;
                                break;
                            case 3: // adverb
                                follows = false;
                                break;
                            case 4: // adjective
                                follows = false;
                                break;
                            case 5: // preposition
                                follows = false;
                                break;
                            case 6: // conjunction
                                follows = true;
                                break;
                            case 7: // determiner
                                follows = false;
                                break;
                            case 8: // interjection
                                follows = true;
                                break;
                            case 9: // exclamation
                                follows = true;
                                break;
                            case 10: //NoType
                                follows = true;
                                break;
                            case 11: // auxiliary
                                follows = true;
                                break;
                            case 12: // article
                                follows = false;
                                break;
                            case 13: // punctuation
                                follows = true;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 6: // conjunction //conjunction
                        switch (e) {
                            case 0: // noun
                                follows = true;
                                break;
                            case 1: // pronoun
                                follows = false;
                                break;
                            case 2: // verb
                                follows = true;
                                break;
                            case 3: // adverb
                                follows = true;
                                break;
                            case 4: // adjective
                                follows = true;
                                break;
                            case 5: // preposition
                                follows = true; // change
                                break;
                            case 6: // conjunction
                                follows = false;
                                break;
                            case 7: // determiner
                                follows = false; // change
                                break;
                            case 8: // interjection
                                follows = true;
                                break;
                            case 9: // exclamation
                                follows = true;
                                break;
                            case 10: //NoType
                                follows = true;
                                break;
                            case 11: // auxiliary
                                follows = true;
                                break;
                            case 12: // article
                                follows = false;
                                break;
                            case 13: // punctuation
                                follows = true;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 7: // determiner //determiner
                        switch (e) {
                            case 0: // noun
                                follows = true;
                                break;
                            case 1: // pronoun
                                follows = false;
                                break;
                            case 2: // verb
                                follows = true;
                                break;
                            case 3: // adverb
                                follows = false;
                                break;
                            case 4: // adjective
                                follows = false;
                                break;
                            case 5: // preposition
                                follows = true;
                                break;
                            case 6: // conjunction
                                follows = false;
                                break;
                            case 7: // determiner
                                follows = false;
                                break;
                            case 8: // interjection
                                follows = true;
                                break;
                            case 9: // exclamation
                                follows = true;
                                break;
                            case 10: //NoType
                                follows = true;
                                break;
                            case 11: // auxiliary
                                follows = true;
                                break;
                            case 12: // article
                                follows = false;
                                break;
                            case 13: // punctuation
                                follows = true;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 8: // interjection //interjection
                        switch (e) {
                            case 0: // noun
                                follows = true;
                                break;
                            case 1: // pronoun
                                follows = false;
                                break;
                            case 2: // verb
                                follows = false;
                                break;
                            case 3: // adverb
                                follows = false;
                                break;
                            case 4: // adjective
                                follows = false;
                                break;
                            case 5: // preposition
                                follows = true;
                                break;
                            case 6: // conjunction
                                follows = false;
                                break;
                            case 7: // determiner
                                follows = false;
                                break;
                            case 8: // interjection
                                follows = true;
                                break;
                            case 9: // exclamation
                                follows = true;
                                break;
                            case 10: //NoType
                                follows = true;
                                break;
                            case 11: // auxiliary
                                follows = true;
                                break;
                            case 12: // article
                                follows = false;
                                break;
                            case 13: // punctuation
                                follows = true;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 9: // exclamation //exclamation
                        switch (e) {
                            case 0: // noun
                                follows = true;
                                break;
                            case 1: // pronoun
                                follows = false;
                                break;
                            case 2: // verb
                                follows = false;
                                break;
                            case 3: // adverb
                                follows = false;
                                break;
                            case 4: // adjective
                                follows = false;
                                break;
                            case 5: // preposition
                                follows = true;
                                break;
                            case 6: // conjunction
                                follows = false;
                                break;
                            case 7: // determiner
                                follows = false;
                                break;
                            case 8: // interjection
                                follows = true;
                                break;
                            case 9: // exclamation
                                follows = true;
                                break;
                            case 10: //NoType
                                follows = true;
                                break;
                            case 11: // auxiliary
                                follows = true;
                                break;
                            case 12: // article
                                follows = false;
                                break;
                            case 13: // punctuation
                                follows = true;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 10: //NoType //NoType
                        switch (e) {
                            case 0: // noun
                                follows = true;
                                break;
                            case 1: // pronoun
                                follows = false;
                                break;
                            case 2: // verb
                                follows = false;
                                break;
                            case 3: // adverb
                                follows = false;
                                break;
                            case 4: // adjective
                                follows = false;
                                break;
                            case 5: // preposition
                                follows = true;
                                break;
                            case 6: // conjunction
                                follows = false;
                                break;
                            case 7: // determiner
                                follows = false;
                                break;
                            case 8: // interjection
                                follows = true;
                                break;
                            case 9: // exclamation
                                follows = true;
                                break;
                            case 10: //NoType
                                follows = true;
                                break;
                            case 11: // auxiliary
                                follows = true;
                                break;
                            case 12: // article
                                follows = false;
                                break;
                            case 13: // punctuation
                                follows = true;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 11: //auxiliary
                        switch (e) {
                            case 0: // noun
                                follows = true;
                                break;
                            case 1: // pronoun
                                follows = false;
                                break;
                            case 2: // verb
                                follows = false;
                                break;
                            case 3: // adverb
                                follows = false;
                                break;
                            case 4: // adjective
                                follows = false;
                                break;
                            case 5: // preposition
                                follows = true;
                                break;
                            case 6: // conjunction
                                follows = false;
                                break;
                            case 7: // determiner
                                follows = false;
                                break;
                            case 8: // interjection
                                follows = true;
                                break;
                            case 9: // exclamation
                                follows = true;
                                break;
                            case 10: //NoType
                                follows = true;
                                break;
                            case 11: // auxiliary
                                follows = false;
                                break;
                            case 12: // article
                                follows = false;
                                break;
                            case 13: // punctuation
                                follows = true;
                                break;
                            default:
                                break;
                        }
                    case 12: //article
                        switch (e) {
                        case 0: // noun
                            follows = true;
                            break;
                        case 1: // pronoun
                            follows = false;
                            break;
                        case 2: // verb
                            follows = false;
                            break;
                        case 3: // adverb
                            follows = false;
                            break;
                        case 4: // adjective
                            follows = false;
                            break;
                        case 5: // preposition
                            follows = true;
                            break;
                        case 6: // conjunction
                            follows = false;
                            break;
                        case 7: // determiner
                            follows = false;
                            break;
                        case 8: // interjection
                            follows = true;
                            break;
                        case 9: // exclamation
                            follows = true;
                            break;
                        case 10: //NoType
                            follows = true;
                            break;
                        case 11: // auxiliary
                            follows = false;
                            break;
                        case 12: // article
                            follows = false;
                            break;
                        case 13: // punctuation
                            follows = true;
                            break;
                        default:
                            break;
                        }
                    case 13: //punctuation
                        switch (e) {
                        case 0: // noun
                            follows = true;
                            break;
                        case 1: // pronoun
                            follows = false;
                            break;
                        case 2: // verb
                            follows = false;
                            break;
                        case 3: // adverb
                            follows = false;
                            break;
                        case 4: // adjective
                            follows = false;
                            break;
                        case 5: // preposition
                            follows = true;
                            break;
                        case 6: // conjunction
                            follows = false;
                            break;
                        case 7: // determiner
                            follows = false;
                            break;
                        case 8: // interjection
                            follows = true;
                            break;
                        case 9: // exclamation
                            follows = true;
                            break;
                        case 10: //NoType
                            follows = true;
                            break;
                        case 11: // auxiliary
                            follows = false;
                            break;
                        case 12: // article
                            follows = false;
                            break;
                        case 13: // punctuation
                            follows = true;
                            break;
                        default:
                            break;
                        }
                        break;
                    default:
                        // TODO CHANGE THIS 
                        std::cout << "Defaulting for some reason." + std::to_string(i) + " on i ";
                        follows = true;
                        break;
                }
                grammar[i][e] = follows;
                if (grammar[i][e]) { std::cout << std::to_string(i) + std::to_string(e) + " True "; }
                else { std::cout << std::to_string(i) + std::to_string(e) + " False "; }
            }
        }
}

// load sentence structures
void StructureManager::LoadStructures()
{
	std::fstream strucs("SentenceStructures.txt");
	std::string structure = "";
	if (strucs.is_open())
	{
		std::cout << " Loading Structure File..." << std::endl;
		int check;
		std::shared_ptr<SentencePoint> current = std::make_shared<SentencePoint>();
		while (std::getline(strucs, structure) && !EOF)
		{
			//TODO: load sentence structures into hashmap
			if (!structure.empty())
			{
				if (structure[1] != ' ') { current = createSentenceNode(structure); addSentenceNode(current); }
				else
				{
					if (structure[0] == 'p')
					{
						structure.erase(structure.begin());
						current->addPrev(createSentenceNode(structure));
					}
					else if (structure[0] == 'n')
					{
						structure.erase(structure.begin());
						current->addNext(createSentenceNode(structure));
					}
				}
			}
			current = std::make_shared<SentencePoint>();
		}
		//strucs.flush();
		strucs.close();
		std::cout << " Structure File Loaded! " << std::endl;
	}
	else { strucs.close(); std::cout << "\n Could not open structure file. \n"; }
}

// dump data to file
void StructureManager::dumpStructureData()
{
	std::ofstream strucs("SentenceStructures.txt");
	if (strucs.is_open())
	{
		std::cout << " Saving Structure File..." << std::endl;

		// dumping sentences and lists to file
		for (auto& sentence : sentenceStructures)
		{
			strucs << sentence.second->getSentence() << std::endl;
			for (auto& prev : sentence.second->getPrevList())
			{
				if (prev != nullptr) { strucs << "p " << prev->getSentence() << std::endl; }
			}
			for (auto& next : sentence.second->getNextList())
			{
				if (next != nullptr) { strucs << "n " << next->getSentence() << std::endl; }
			}
		}
		//strucs.flush();
		strucs.close();
		std::cout << " Structure File Saved! " << std::endl;
	}
	else
	{
		std::cerr << " Failed to create/open structure file. " << std::endl;
	}
}