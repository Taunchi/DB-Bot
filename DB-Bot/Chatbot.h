#pragma once
#ifndef CHATBOT_H
#define CHATBOT_H

#include <string>
//#include "State.h"
#include "StructureManager.h"
//#include "LoadingState.h"
//#include "ListeningState.h"
//#include "SpeakingState.h"
//#include "AnalysisState.h"
//#include "TrainingState.h"

enum state 
{
	LOADING = 0,
	TRAINING,
	LISTENING,
	SPEAKING,
	ANALYSIS
};
//class State;
class Chatbot {
private:
	//LoadingState loadingState;
	//AnalysisState analysisState;
	//ListeningState listeningState;
	//SpeakingState speakingState;
	//TrainingState trainingState;
	
	std::string name;

public:
	//State current;
	StructureManager* structureManager;
	//WordManager wordManager;
	
	//Chatbot();
	Chatbot(StructureManager *manager2) 
	{
		//analysisState = new AnalysisState();
		//listeningState = new ListeningState();
		//trainingState = new TrainingState();
		//current = &loadingState;
		//LoadingState* tester = new LoadingState;
		//State* current = new LoadingState();
		//State current = tester;
		// initialize state machine
		//loading(this, manager);
		//wordManager = manager;
		setStructureManager(manager2);
	};

	void setStructureManager(StructureManager* manager) {
		structureManager = manager;
	}
	/*
	// set bot state
	void setState(int state) 
	{
		switch (state)
		{
			case LOADING: 
				current = &loadingState;
				break;
			case TRAINING:
				current = &trainingState;
				break;
			case LISTENING:
				current = &listeningState;
				break;
			case ANALYSIS:
				current = &analysisState;
				break;

		}
	};

	void training(Chatbot* ins) { current->training(this); }
	void loading(Chatbot* ins, WordManager manager) { current->loading(this); }
	void listening(Chatbot* ins) { current->listening(this); }
	void speaking(Chatbot* ins) { current->speaking(this); }
	void analyzing(Chatbot* ins) { current->analyzing(this); }
	*/
	~Chatbot() 
	{
		//delete loadingState;
		//delete analysisState;
		//delete listeningState;
		//delete trainingState;
		//delete current;
	};
};
#endif // !BOTSELF_H