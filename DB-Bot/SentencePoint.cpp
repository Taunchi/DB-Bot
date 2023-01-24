#include "SentencePoint.h"

SentencePoint::SentencePoint() { struc = nullptr; prev = nullptr; next = nullptr; }

// set current structure
void SentencePoint::setStructure(std::shared_ptr<SentenceStructure> sp) { struc = sp; }

// setters for prev/next sentencepoints
void SentencePoint::setPrev(std::shared_ptr<SentencePoint> spp) { prev = spp; }
void SentencePoint::setNext(std::shared_ptr<SentencePoint> spn) { next = spn; }

// add nexts/prevs to list
void SentencePoint::addPrev(std::shared_ptr<SentencePoint> spp) { prevList.emplace_back(spp); }
void SentencePoint::addNext(std::shared_ptr<SentencePoint> spn) { nextList.emplace_back(spn); }

// get current structure and get next/prev sentencepoints
std::shared_ptr<SentenceStructure> SentencePoint::getStructure() { return struc; }
std::shared_ptr<SentencePoint> SentencePoint::getNext() { return next; }
std::shared_ptr<SentencePoint> SentencePoint::getPrev() { return prev; }
std::list<std::shared_ptr<SentencePoint>> SentencePoint::getNextList() { return nextList; }
std::list<std::shared_ptr<SentencePoint>> SentencePoint::getPrevList() { return prevList; }

// sentence structure proxy functions

// returns structure as string
std::string SentencePoint::getSentence() { if (struc != nullptr) { return struc->getSentence(); } };
// returns hash of given structure
std::string SentencePoint::strucHash(std::shared_ptr<SentenceStructure> ss)
{
	if (struc == nullptr)
	{
		struc = ss;
		return ss->strucHash(ss);
	}
	else
	{
		return struc->strucHash();
	}
}
// returns hash of selft
std::string SentencePoint::strucHash()
{
	if (struc != nullptr) { return struc->strucHash(); }
}
// returns vector of word object pointers
std::vector<std::shared_ptr<Word>> SentencePoint::getWords() { if (struc != nullptr) { return struc->getWords(); } }
// returns a duplicate instance of sentence structure
std::shared_ptr<SentenceStructure> SentencePoint::getInst() { if (struc != nullptr) { return struc->getInst(); } }