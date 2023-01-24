#pragma once
#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <list>
//#include "WordPoint.h"

class Word
{
private:
	std::string wordName;
	std::string puncName;
	std::string type;
	std::list<std::string> wordtypes;
	std::string noun, verb, adjective, adverb, pronoun, preposition, conjunction, determiner, exclamation, interjection , auxiliary, article, punctuation, noType;
	bool isPunc = false;
	bool isNoun = false, isVerb = false, isAdjective = false, isAdverb = false, isPronoun = false, 
		 isPreposition = false, isConjunction = false, isDeterminer = false, isExclamation = false, 
		 isInterjection = false, isAuxiliary = false, isArticle = false, isNOTYPE = false;
	//bool types;
	// TODO 8/7/2022 add interjection
	// TODO 8/9/2022 add other word types (parts of speech)
	enum types {
		Noun,
		Adjective,
		Verb,
		Adverb,
		Pronoun,
		Preposition,
		Conjunction,
		Determiner,
		Exclamation,
		Interjection,
		Auxiliary,
		Article,
		Punctuation,
		NoType
	};

	types resolveTypes(std::string type)
	{
		if (type == "noun") return Noun;
		if (type == "adjective") return Adjective;
		if (type == "verb") return Verb;
		if (type == "adverb") return Adverb;
		if (type == "pronoun") return Pronoun;
		if (type == "preposition") return Preposition;
		if (type == "conjunction") return Conjunction;
		if (type == "determiner") return Determiner;
		if (type == "exclamation") return Exclamation;
		if (type == "interjection") return Interjection;
		if (type == "auxiliary") return Auxiliary;
		if (type == "article") return Article;
		if (type == "punctuation") return Punctuation;
		if (type == "NoType") return NoType;
	}

public:
	Word(std::string word) :wordName(word) {};
	Word(std::string word, std::string type) { this->type = type; wordName = word; };
	Word():wordName(""), type(""), noun(""), verb(""), adjective(""), adverb(""), pronoun(""), preposition(""), conjunction(""),
		determiner(""), exclamation(""), interjection(""), auxiliary(""), article(""), punctuation(""), noType("") {}
	Word(std::string word, std::string type, std::string noun, std::string verb, std::string adjective, std::string adverb, 
		std::string pronoun, std::string preposition, std::string conjunction, std::string determiner, std::string exclamation, std::string interjection, std::string auxiliary,
		std::string article, std::string punctuation, std::string noType):
		wordName(word),type(type), noun(noun), verb(verb), adjective(adjective), adverb(adverb), pronoun(pronoun), 
		preposition(preposition),conjunction(conjunction),determiner(determiner), exclamation(exclamation), interjection(interjection), auxiliary(auxiliary), article(article), 
		punctuation(punctuation), noType(noType) {}
	//Word(const Word &real)
	//{
	//	wordName = real.word;
	//	type = real.type;
	//	definition = real.definition;
	//}
	Word* point(){return this;}
	// TODO: node creation method, new node creation and node return and new node return
	// when word is read creates node
	// if read first nothing happens
	// if read after another word, 
	// sets previousnode to previous word node return and sets previousnode's nextnode to current word's return node
	// TODO: need list management class and WordNode/WordPoint class
	// OR it reads sentence
	// came up with useless way to predict text quickly if constantly reading input
	// OR OR
	//
	// Word objects carry a list of SentenceStructureNodes
	// sentencestructurenodes hold reference to sentence structure or stucture obj?
	// ---- also has multiple nextnodes which are picked based upon weights for each node 
	// read sentence pulls first words sentence nodes list and compares read sentence structure to all nodes in list
	// if no node match, create new node and push to word node list
	// two different methods - one for reading input and output and writing to nodes
	// ----------------------- one for reading input and generating output from nodes
	//TODO: figure out how to implement this more quickly.. uniquely numbered structures somehow? structurenode hashmap?
	// ----uniquely numbered words for structure hashmap?
	// the sentence structures are hashed in unordered_map? ooooor
	// create a map of structures with the key for each being a string constructed from the first letter and last of each word+punc
	// ----in the structure

	// Get type of word
	std::string getType()
	{
		return type;
	}

	//TODO 8/11/2022 BROKE something with the isTypes return
	bool checkType(std::string)
	{
		
		switch (resolveTypes(type))
		{
		case Adjective: {
			return isAdjective;
			break;
		}
		case Noun: {
			return isNoun;
			break;
		}
		case Adverb: {
			return isAdverb;
			break;
		}
		case Determiner: {
			return isDeterminer;
			break;
		}
		case Preposition: {
			return isPreposition;
			break;
		}
		case Exclamation: {
			return isExclamation;
			break;
		}
		case Conjunction: {
			return isConjunction;
			break;
		}
		case Pronoun: {
			return isPronoun;
			break;
		}
		case Verb: {
			return isVerb;
			break;
		}
		case Interjection: {
			return isInterjection;
			break;
		}
		case Auxiliary: {
			return isAuxiliary;
			break;
		}
		case Article: {
			return isArticle;
			break;
		}
		case Punctuation: {
			return isPunc;
			break;
		}
		case NoType: {
			return isNOTYPE;
			break;
		}
				 // handles Option_Invalid and any other missing/unmapped cases
		default: {
			return false;
			break;
		}
		}
	}

	void setType(std::string type, bool isType)
	{
		switch (resolveTypes(type))
		{
			case Adjective: {
				if (isType) { isAdjective = true; }
				this->type = type;
				return;
				break;
			}
			case Noun: {
				if (isType) { isNoun = true; }
				this->type = type;
				return;
				break;
			}
			case Adverb: {
				if (isType) { isAdverb = true; }
				this->type = type;
				return;
				break;
			}
			case Determiner: {
				if (isType) { isDeterminer = true;
				this->type = type;
				}
				return;
				break;
			}
			case Preposition: {
				if (isType) { isPreposition = true; }
				this->type = type;
				return;
				break;
			}
			case Exclamation: {
				if (isType) { isExclamation = true; }
				this->type = type;
				return;
				break;
			}
			case Conjunction: {
				if (isType) { isConjunction = true; }
				this->type = type;
				return;
				break;
			}
			case Pronoun: {
				if (isType) { isPronoun = true; }
				this->type = type;
				return;
				break;
			}
			case Verb: {
				if (isType) { isVerb = true; }
				this->type = type;
				return;
				break;
			}
			case Interjection: {
				if (isType) { isInterjection = true; }
				this->type = type;
				return;
				break;
			}
			case Auxiliary: {
				if (isType) { isAuxiliary = true; }
				this->type = type;
				return;
				break;
			}
			case Article: {
				if (isType) { isArticle = true; }
				this->type = type;
				return;
				break;
			}
			case Punctuation: {
				if (isType) { isPunc = true; }
				this->type = type;
				return;
				break;
			}
			case NoType: {
				if (isType) { isNOTYPE = true; }
				this->type = type;
				return;
				break;
			}
					// handles Option_Invalid and any other missing/unmapped cases
			default: {
				this->type = type;
				break;
			}
		}
		this->type = type;
	}

	void setTypes(std::list<std::string> types, bool isType)
	{
		// TODO change? 8/11/2022 or I coulld just do this
		// Actually, to get the bools set need the for and switch statements
		
		for (auto type : types)
		{
			switch (resolveTypes(type))
				{
				case Adjective: {
					if (isType) { isAdjective = true; }
					this->type = type;
					return;
					break;
				}
				case Noun: {
					if (isType) { isNoun = true; }
					this->type = type;
					return;
					break;
				}
				case Adverb: {
					if (isType) { isAdverb = true; }
					this->type = type;
					return;
					break;
				}
				case Determiner: {
					if (isType) { isDeterminer = true; }
					this->type = type;
					return;
					break;
				}
				case Preposition: {
					if (isType) { isPreposition = true; }
					this->type = type;
					return;
					break;
				}
				case Exclamation: {
					if (isType) { isExclamation = true; }
					this->type = type;
					return;
					break;
				}
				case Conjunction: {
					if (isType) { isConjunction = true; }
					this->type = type;
					return;
					break;
				}
				case Pronoun: {
					if (isType) { isPronoun = true; }
					this->type = type;
					return;
					break;
				}
				case Verb: {
					if (isType) { isVerb = true; }
					this->type = type;
					return;
					break;
				}
				case Interjection: {
					if (isType) { isInterjection = true; }
					this->type = type;
					return;
					break;
				}
				case Auxiliary: {
					if (isType) { isAuxiliary = true; }
					this->type = type;
					return;
					break;
				}
				case Article: {
					if (isType) { isArticle = true; }
					this->type = type;
					return;
					break;
				}
				case Punctuation: {
					if (isType) { isPunc = true; }
					this->type = type;
					return;
					break;
				}
				case NoType: {
					if (isType) { isNOTYPE = true; }
					this->type = type;
					return;
					break;
				}
								 // handles Option_Invalid and any other missing/unmapped cases
				default: {
					break;
				}
			}
			wordtypes.push_back(type);
		}
	}

	// sets as punctuation
	void setPunc()
	{
		type = "punctuation";
		isPunc = true;
	}

	void setName(std::string name)
	{
		wordName = name;
	}

	std::string getName()
	{
		return wordName;
	}
	//~Word();
};

#endif // !WORD_H
