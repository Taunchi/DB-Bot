#pragma once
#ifndef STRUCTUREMANAGER_H
#define STRUCTUREMANAGER_H

#include "WordManager.h"
#include "SentencePoint.h"

class StructureManager
{
	// structural unordered map of sentence structures
	std::unordered_map<std::string, std::shared_ptr<SentencePoint> > sentenceStructures;
private:
	bool grammar[14][14];
public:
	std::shared_ptr<WordManager> dictionary;
	StructureManager();
	StructureManager(std::shared_ptr<WordManager> dictionary);

	// speak random sentence
	void speakRandom();

	// generate sentences
	void generateSentence();

	// add sentence structrure to structural map
	void addSentence(std::shared_ptr<SentenceStructure> ss);

	// add sentence node to structural map
	void addSentenceNode(std::shared_ptr<SentencePoint> sp);

	// create and add sentence node from sentence string
	void addSentenceNode(std::string sentence);

	// create sentence structure node from sentence string
	std::shared_ptr<SentencePoint> createSentenceNode(std::string sentence);

	// create sentence structure node from sentence structure
	std::shared_ptr<SentencePoint> createSentenceNode(std::shared_ptr<SentenceStructure> sentence);

	// create shared_ptr vector of word objects from dictionary using sentence string
	std::vector<std::shared_ptr<Word>> getWords(std::string sentence);

	// loads booleans for grammatical structure array
	void LoadGrammarArray();

	// load sentence structures
	void LoadStructures();
	
	// dump data to file
	void dumpStructureData();

	~StructureManager()
	{
		dumpStructureData();
	}
};
#endif // !STRUCTUREMANAGER_H
