#pragma once
#ifndef LISTENINGSTATE_H
#define LISTENINGSTATE_H
#include "State.h"

class ListeningState : public State
{
public:
	ListeningState() {
		std::cout << "OnState State Initialized" << std::endl;
	}

	void training(Chatbot* ins)
	{
		// train
		//ins->setState(LOADING);
	}
	void loading(Chatbot* ins)
	{
		//ins->setState(LOADING);
	}
	void listening(Chatbot* ins)
	{
		// listen and on input switch to analysis state
		//ins->setState(ANALYSIS);
	}
	void speaking(Chatbot* ins)
	{
		//ins->setState(SPEAKING);
	}
	void analyzing(Chatbot* ins)
	{
		//ins->setState(ANALYSIS);
	}
};
#endif /* !LISTENINGSTATE_H */