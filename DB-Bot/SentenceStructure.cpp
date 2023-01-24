#include "SentenceStructure.h"

// EDITED 8/4/2022
SentenceStructure::SentenceStructure(std::vector<std::shared_ptr<Word>> words)
{
	//testing this? new 8/4/2022
	std::for_each(words.begin(), words.end(), [&](std::shared_ptr<Word> word)
		{
			types.push_back(word->getType());
			this->words.emplace_back(word);
		});
	// OLD
	//for (int i = words.begin(); i != words.end(); i++)
	//{
		//TODO: (*words.at[i]) ???
	//	this->words.emplace_back(words[i]);
	//}
	//for (int i : words)
	//{
	//	this->words.emplace_back(words[i]);
	//}
}

SentenceStructure::SentenceStructure(std::vector<std::shared_ptr<Word>> words, std::string structure)
{
	//TODO get order of words types for structure 8/14/2022
	//std::for_each(words.begin(), words.end(), [&](Word& word)
	//	{
	//		this->words.push_back(word);
	//	});
	// 8/4/2022 new
	for (int i = words.size(); i >= 0; i--)
	{
		// words.at(i) vs words[i]
		// [i] vs .at(i)
		types.push_back(words[i]->getType());
		this->words.push_back(words.at(i));
	}
	//for (auto i = words.begin(); i != words.end(); i++)
	//{
	//	//TODO: (*words.at[i]) ???
	//	this->words.push_back(words.at[i]);
	//}
}

// returns string format of words
std::string SentenceStructure::getSentence()
{
	std::string sentStruc;
	//OLD
	//for (auto i = words.begin(); i != words.end(); i++)
	//{
	//	std::string c = i->getName();
	//	//TODO: (*words.at[i])->getName(); dereferencing okay?
	//	if (i != words.begin()) { if (c != "?" || c != "!" || c != "." || c != ",") { sentStruc += " " + words.at[i]->getName(); } else { sentStruc += words.at[i]->getName(); } }
	//	else { sentStruc += words.at[i]->getName(); }
	//}
	// 8/4/2022 new testing
	// 8/7/2022 new testing
	//for (int i = words.size(); i >= 0; i--)
	std::for_each(words.begin(), words.end(), [&](std::shared_ptr<Word> word) {
		//std::string c = words.at(i)->getName();
		std::string c = word->getName();
		if (!words.front()->getName().empty())
		{
			if (word != words.front())
			{
				if (c != "?" || c != "!" || c != "." || c != ",")
				{
					sentStruc += " " + c;
				}
				else { sentStruc += c; }
			}
			else { 
				for (int i = 0; i < c.length(); i++) {
					if (i == 0)
					{
						sentStruc += std::toupper(c[i]);
					}
					else
					{
						sentStruc += c[i];
					}
				}
			}
		}
	});
	return sentStruc;
}
// return hash of new struc
std::string SentenceStructure::strucHash(std::shared_ptr<SentenceStructure> ss)
{
	hash = "";
	for (std::shared_ptr<Word> i : ss->getWords())
	{
		//hash += (i->getName().front() + i->getName().back());
		hash += i->getName().front();
		//8/7/2022 testing cout
		std::cout << hash + " This is the hash";
	}
	return hash;
}

// return sentence structure hash
std::string SentenceStructure::strucHash()
{
	hash = "";
	//8/7/2022 TESTING
	std::for_each(words.begin(), words.end(), [&](std::shared_ptr<Word> word)
		{
			//hash += (i->getName().front() + i->getName().back());
	//		if (word->getName().front() != ' ')
	//		{
	//			hash += word->getName().front();
	//		}
		});
	//for (std::shared_ptr<Word> i : words)
	//{
	//	//hash += (i->getName().front() + i->getName().back());
	//	std::shared_ptr<Word> temp = i;
	//	if (temp->getName().front() != ' ')
	//	{
	//		hash += i->getName().front();
	//	}
	//}
	return hash;
}

void SentenceStructure::setStrucType(std::string strucType) 
{
	this->strucType = strucType;
}

// get sentence word pointers
std::vector<std::shared_ptr<Word>> SentenceStructure::getWords()
{
	return words;
}

std::shared_ptr<SentenceStructure> SentenceStructure::getInst()
{
	std::unique_ptr<SentenceStructure> inst = std::make_unique<SentenceStructure>(getWords());
	return inst;
}