#include "WordManager.h"

WordManager::WordManager(std::string filename)
{
	changed = 0;
	LoadDictionary(filename);
}

WordManager::WordManager(std::string filename, std::string filename1)
{
	changed = 0;
	//LoadDictionary(filename);
	LoadDictionaryDos(filename1);
}

void WordManager::LoadDictionary(std::string filename)
{
	std::fstream words(filename + ".txt");
	std::string word = "";
	if (words.is_open())
	{
		std::cout << "\n Loading Dictionary..." << std::endl;

		while (std::getline(words, word))
		{
			Word w;
			if (word == "pQu")
			{
				w = Word("?");
			}
			else if (word == "pEx")
			{
				w = Word("!");
			}
			else if (word == "pPe")
			{
				w = Word(".");
			}
			else if (word == "pCo")
			{
				w = Word(",");
			}
			else { w = Word(word); dictionary[word] = w; }
		}
		std::cout << "\n Dictionary Loaded! " << std::endl;
		words.flush();
		words.close();
	}
	else { words.close(); std::cout << "\n Could not open .txt file. \n"; }
}

//TODO TESTING edit later 8/7/2022 // trying to save with definition into dictionary later
void WordManager::LoadDictionaryDos(std::string filename)
{
	std::fstream words(filename + ".txt");
	std::string word = "";
	if (words.is_open())
	{
		std::cout << "\n Loading Dictionary..." << std::endl;

		while (std::getline(words, word))
		{
			Word w;
			if (word == "pQu")
			{
				w = Word("?","punctuation");
				w.setPunc();
			}
			else if (word == "pEx")
			{
				w = Word("!", "punctuation");
				w.setPunc();
			}
			else if (word == "pPe")
			{
				w = Word(".", "punctuation");
				w.setPunc();
			}
			else if (word == "pCo")
			{
				w = Word(",", "punctuation");
				w.setPunc();
			}
			else 
			{ 
				std::string tempWord = "";
				std::string wordType = "";
				std::list<std::string> wordTypes;
				std::string wordDef = "";
				int count = 0;
				for (char letter : word)
				{
					if (letter == ' ' || letter == '|')
					{
						if (letter == '|')
						{
							count++;
						}
					}
					else if (count < 1 && letter != ' ')
					{

						tempWord += letter;
					}
					else if (count == 1)
					{
						if (letter == ',')
						{
							wordTypes.push_back(wordType);
							wordType = "";
						}
						else if(letter != ',' )
						{
							wordType += letter;
						}
					}
					else if (count == 2)
					{
						wordDef += letter;
					}
				}

				if (wordTypes.empty())
				{
					w = Word(tempWord);
					w = Word(tempWord, wordType);
					w.setType(wordType, true);
					w = Word(tempWord, wordType);
					dictionary[tempWord] = w;
				}
				else
				{
					w = Word(tempWord);
					w = Word(tempWord, wordType);
					w.setType(wordType, true);
					w.setTypes(wordTypes, true);
					w = Word(tempWord, wordType);
					dictionary[tempWord] = w;
				}
			}
			std::cout << w.getName();
		}
		std::cout << "\n Dictionary Loaded! " << std::endl;
		words.flush();
		words.close();
	}
	else { words.close(); std::cout << "\n Could not open .txt file. \n"; }
}
	//TODO: void LoadDict() - loads dictionary from json
	// nix that no json just use txt file for now as there are no definitions or word types
	//TODO: void LoadDict() - loads dictionary from .txt file
	// ---- separate function to grab word pointers?
	// create word object

// create word object of (word literal string) and add word to dictionary
void WordManager::addWord(std::string word)
{
	// add word to dictionary file 8/7/2022
	Word w = Word(word);
	dictionary[word] = w;
}

// returns unique word pointer from dictionary via hash (word literal)
std::unique_ptr<Word> WordManager::getWord(std::string word)
{
	//8/7/2022 testing
	if (dictionary.find(word) != dictionary.end())
	{
		
		return std::make_unique<Word>(dictionary.at(word));
	}
	else {
		// TODO add word to dictionary file
		addWord(word);
		//return std::make_unique<Word>("OutOfRangeInDictionary");
		return std::make_unique<Word>(dictionary.at(word));
	}
	
}

// TESTING 8/7/2022 gets random word
std::unique_ptr<Word> WordManager::getRandomWord(std::string type)
{
	bool isType = false;
	//auto tempword = std::make_unique<Word>("blah");
	auto tempy = std::make_unique<Word>();
	while (!isType)
	{
		int randNum = rand() % (dictionary.size() - 1 + 1) + 0;
		auto random_it = std::next(std::begin(dictionary), randNum);
		auto tempword = std::make_unique<Word>(random_it->second.getName(), random_it->second.getType());
		//std::cout << random_it->second.getType();
		//tempword->setType(random_it->second.getType(), true);
		//std::cout << tempword->getType() + "test type " + tempword->getName() + "test name " + " < " + type + " >";
		if (tempword->checkType(type) && tempword->getType() == type)
		{
			
			//TODO PUT BREAK HERE
			tempy->setType(tempword->getType(), true);
			tempword->setType(type, true);
			tempy->setName(tempword->getName());
			//std::cout << tempy->getName() + "this is tempy if type is equal";
			isType = true;
		}
		else if (tempword->getType() == type)
		{
			
			tempy->setType(tempword->getType(), true);
			if (tempword->getType() == "")
			{
				tempy->setType(type, true);
				tempword->setType(type, true);
			}
			tempy->setName(tempword->getName());
			//std::cout << tempy->getName() + "this is tempy if type is equal";
			isType = true;
		}
		else if (tempword->getType() == "")
		{
			tempy->setType(type, true);
			tempword ->setType(type, true);
			tempy->setName(tempword->getName());
			//std::cout << " Word: " + tempword->getName() + " NO TYPE FOR SOME REASON" + " Word Type: " + tempy->getType() + " " + " Looking for " + type + " ";
			tempword->setType(type, true);
			//std::cout << " WORD TYPE:!? " + tempword->getType() + " word type from string: " + type;
			//TODO TESTING 8/11/2022 types missing
			//TODO CHANGE THIS 8/7/2022
			//tempy->setType("pronoun",true);
			//tempy->setName(tempword->getName());
			//TODO add back? 8/9/2022
			isType = true;
		}
		else
		{
			//return std::make_unique<Word>(type);
			isType = false;
		}
	}
	return tempy;
}

// read all words in dictionary
void WordManager::readAll()
{
	for (auto& word : dictionary)
	{
		std::cout << "Word \n" << word.first;
	}
}

// Found this idea to clear the command line on windows/mac https://stackoverflow.com/questions/228617/how-do-i-clear-the-console-in-both-windows-and-linux-using-c
void WordManager::clearScreen()
{
	std::system(CLEAR);
}