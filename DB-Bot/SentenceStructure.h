#pragma once
#ifndef SENTENCESTRUCTURE_H
#define SENTENCESTRUCTURE_H

#include <vector>
#include <algorithm>
#include <memory>
#include "Word.h"


class SentenceStructure
{
private:
	// this does not handle all punctuation or numbers adequately
	std::vector<std::shared_ptr<Word>> words;
	std::string hash;
public:
	std::vector<std::string> types;
	std::string strucType;

	SentenceStructure(std::vector<std::shared_ptr<Word>> words);

	// 8, 4, 2022 added std::vector<std::shared_ptr<Word>> words
	SentenceStructure(std::vector<std::shared_ptr<Word>> words, std::string structure);

	// returns string format of words
	std::string getSentence();

	// return hash of new struc
	std::string strucHash(std::shared_ptr<SentenceStructure> ss);

	// return sentence structure hash
	std::string strucHash();

	// get sentence word pointers
	std::vector<std::shared_ptr<Word>> getWords();

	std::shared_ptr<SentenceStructure> getInst();

	void setStrucType(std::string strucType);

	//TODO: add file dump before deletion
	~SentenceStructure() {}
	// words.clear();
	//for (Word* b : words) { delete b; }
};

#endif // !SENTENCESTRUCTURE_H