#pragma once
#ifndef WORDMANAGER_H
#define WORDMANAGER_H
#ifdef _WIN32
#define CLEAR "CLS"
#else
#define CLEAR "clear"
#endif

#include <fstream>
#include <sstream>
#include <algorithm>
#include <memory>
#include <unordered_map>
#include "Word.h"
#include <string>

class WordManager
{
	std::unordered_map<std::string, Word> dictionary;
private:
	void LoadDictionary(std::string filename);
	void LoadDictionaryDos(std::string filename);
	int changed;
public:
	WordManager();
	WordManager(std::string filename);
	WordManager(std::string filename, std::string filename1);
	//TODO: void LoadDict() - loads dictionary from json
	// nix that no json just use txt file for now as there are no definitions or word types
	//TODO: void LoadDict() - loads dictionary from .txt file
	// ---- separate function to grab word pointers?
	// create word object

	// create word object of (word literal string) and add word to dictionary
	void addWord(std::string word);

	// returns unique word pointer from dictionary via hash (word literal)
	std::unique_ptr<Word> getWord(std::string word);

	//TESTING 8/7/2022
	std::unique_ptr<Word> getRandomWord(std::string type);

	// read all words in dictionary
	void readAll();

	// Found this idea to clear the command line on windows/mac https://stackoverflow.com/questions/228617/how-do-i-clear-the-console-in-both-windows-and-linux-using-c
	void clearScreen();

	~WordManager()
	{
		if (changed != 0)
		{
			// dump dictionary to file if words added
		}
	};
};
#endif // !WORDMANAGER_H
