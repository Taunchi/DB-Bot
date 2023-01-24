/*
Dion Boyer, dboyer2@live.nmhu.edu, Final - Chatbot
*/
////////////////////////////////////
// BotDriver.cpp
////////////////////////////////////
//#include <cstdlib>
#include <iostream>
#include <string>
#include "Hash.h"
#include "WordManager.h"
#include "StructureManager.h"
#include "Chatbot.h"

enum BotMachineState
{
	CHATTING, HEARING, THINKING
};

int main(int argc, char** argv)
{
	//new WordManager("dictNoDef.txt");
	//WordManager m("dictNoDef");
	// dictWithDef
	auto wm = std::make_shared<WordManager>("dictNoDef", "dictWithDef");
	StructureManager sm(wm);

	StructureManager* smp = &sm;
	Chatbot cb(smp);
	cb.structureManager->addSentenceNode("Are you a cat or a dog person?");
	cb.structureManager->addSentenceNode("I ran a long way to get here.");
	cb.structureManager->addSentenceNode("I have to pee.");
	cb.structureManager->addSentenceNode("I went to pee.");
	cb.structureManager->addSentenceNode("There is a dog in the attic.");
	cb.structureManager->addSentenceNode("Run very fast!");
	cb.structureManager->addSentenceNode("What's that smell?");
	cb.structureManager->addSentenceNode("Hey");
	cb.structureManager->addSentenceNode("Hi");
	cb.structureManager->addSentenceNode("Hello");
	cb.structureManager->addSentenceNode("How are you?");
	cb.structureManager->addSentenceNode("What's up?");
	cb.structureManager->addSentenceNode("What are you doing?");
	cb.structureManager->addSentenceNode("What are you thinking about?");
	cb.structureManager->addSentenceNode("I had an idea for a chatbot.");
	cb.structureManager->addSentenceNode("Where are you going?");
	cb.structureManager->addSentenceNode("How long will you be gone?");
	cb.structureManager->addSentenceNode("Say something cool.");
	cb.structureManager->addSentenceNode("These are hardcoded phrases.");
	cb.structureManager->addSentenceNode("Is this random enough?");
	cb.structureManager->addSentenceNode("Hmmm...");
	cb.structureManager->addSentenceNode("You have an extra space.");
	cb.structureManager->addSentenceNode("I'm thinking...");
	cb.structureManager->addSentenceNode("I feel happy!");
	cb.structureManager->addSentenceNode("I feel sad!");
	cb.structureManager->addSentenceNode("I feel like I have to pee.");
	cb.structureManager->speakRandom();
	//std::cin;
	bool testing = true;
	int count = 0;
	std::string input;
	while (testing) {
		std::cout << "\n >";
		//std::getline(std::cin, input, '\n');
		//std::cin >> input;
		std::cout << "\n ";
		
		if (input == "okay") {
			testing = false;
		}
		else
		{
			cb.structureManager->speakRandom();
			//cb.structureManager->addSentenceNode(input);
			//TEST THIS MORE FIX GENERATION TODO
			//cbDos.structureManager->generateSentence();
			cb.structureManager->generateSentence();
			//std::cout << cb.structureManager->dictionary->getRandomWord("verb");
		}
		count++;
		if (count > 250) { testing = false; }
	}
	std::getline(std::cin, input, '\n');
	//m.readAll();
	//TESTING
	//Chatbot cb(m);
	//cb.wordManager.readAll();
	//cb.wordManager.addWord("dogface");
	//std::cout << "dogface";
	//auto blah =  cb.wordManager.getWord("dogface");
	//std::cout << &blah;
	//TODO:
	// every load needs to read in the file of words and sentence structures from json
	// wordmanager reads in word file
	// structuremanager reads in sentence structure file
	// wordmanager creates all word objects and pushes them into a hashmap
	// structuremanager creates all sentencestructure objects (using words of first letters and puncs to push them into a hashmap 
	// ---and then uses info from file to create list of node objects (filling in prev list and next list sentence structure nodes as it goes along



	//TODO: also apply state switching
	// start by printing a message
	// await user input
	// retrieve user input
	// switch from listening state
	// in analysis state
	// deconstruct user sentence 
	// hash user sentence 
	// check hashmap of sentence structures

	// if sentence struc exists - access struc node (check weights for each next node) get next node with heaviest weights
	// access next node struc pointer
	// retrieve word info from struc word list
	// for each word in struc word list += wordName to string
	// print string
	// switch to listening state

	// if no sentence struc exists - create new sentence structure object + node and push it to the hashmaprehash user input - the last word
	// if previous sentence then grab previous sentence and push to new node object prev list
	// maybe just try replacing verb/noun/pronouns for matching later
	// maybe print "Well that's new... Thinking..."


	//^^^^^ for user input

	//TODO: read in training data (sentences) without user input
	// deconstruct and create nodes if it doesn't exist. 
	// first input just creates one node and sentence structure object with empty vectors for prev/next nodes
	// 

}