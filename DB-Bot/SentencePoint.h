#pragma once
#ifndef SENTENCEPOINT_H
#define SENTENCEPOINT_H

#include <iostream>
#include "SentenceStructure.h"
#include <list>

class SentencePoint
{
private:
	// predictive next/prev struc pointer
	std::list<std::shared_ptr<SentencePoint>> nextList;
	std::list<std::shared_ptr<SentencePoint>> prevList;
	// 8/20/2022 weights for lists
	std::list<int> nextWeights;
	std::list<int> prevWeights;
	// self/current struc pointer
	std::shared_ptr<SentenceStructure> struc;
	std::shared_ptr<SentencePoint> prev;
	std::shared_ptr<SentencePoint> next;

public:
	SentencePoint();

	~SentencePoint()
	{
		//TODO: delete the word objects in struc appropriately
	}

	// set current structure
	void setStructure(std::shared_ptr<SentenceStructure> sp);

	// setters for prev/next sentencepoints
	void setPrev(std::shared_ptr<SentencePoint> spp);
	void setNext(std::shared_ptr<SentencePoint> spn);

	// add nexts/prevs to list
	void addPrev(std::shared_ptr<SentencePoint> spp);
	void addNext(std::shared_ptr<SentencePoint> spn);

	// get current structure and get next/prev sentencepoints
	std::shared_ptr<SentenceStructure> getStructure();
	std::shared_ptr<SentencePoint> getNext();
	std::shared_ptr<SentencePoint>getPrev();
	std::list<std::shared_ptr<SentencePoint>> getNextList();
	std::list<std::shared_ptr<SentencePoint>> getPrevList();

	// sentence structure proxy functions

	// returns structure as string
	std::string getSentence();
	// returns hash of given structure
	std::string strucHash(std::shared_ptr<SentenceStructure> ss);
	// returns hash of selft
	std::string strucHash();
	// returns vector of word object pointers
	std::vector<std::shared_ptr<Word>> getWords();
	// returns a duplicate instance of sentence structure
	std::shared_ptr<SentenceStructure> getInst();
};

#endif

/*
Use of Proxy pattern with nodes
*/