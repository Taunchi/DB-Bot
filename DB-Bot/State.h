#pragma once
#ifndef STATE_H
#define STATE_H
#include <iostream>
#include "Chatbot.h"
//#include "ListeningState.h"
//#include "AnalysisState.h"
//#include "LoadingState.h"
//#include "TrainingState.h"

class Chatbot;
class State
{
protected:
	//WordManager manager();
	//Chatbot ins(WordManager manager);
	
public:
	Chatbot* ins();
	State() {}
	virtual void training(Chatbot* ins) {}
	virtual void loading(Chatbot* ins) {}
	virtual void listening(Chatbot* ins) {}
	virtual void speaking(Chatbot* ins) {}
	virtual void analyzing(Chatbot* ins) {}
};
#endif /* !STATE_H */