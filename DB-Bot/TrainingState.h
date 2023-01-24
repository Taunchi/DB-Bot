#pragma once
#ifndef TRAININGSTATE_H
#define TRAININGSTATE_H
#include "State.h"

class TrainingState : public State
{
public:
	TrainingState() {
		std::cout << "OnState State Initialized" << std::endl;
	}

	void training(Chatbot* ins)
	{
		// train
		//ins->setState(LOADING);
	}
	void loading(Chatbot* ins)
	{
		//load stuff then go to listening
		//ins->setState(LOADING);
	}
	void listening(Chatbot* ins)
	{
		//ins->setState(LISTENING);
	}
	void speaking(Chatbot* ins)
	{
		// speak and go to listening
		//ins->setState(SPEAKING);
	}
	void analyzing(Chatbot* ins)
	{
		//ins->setState(ANALYSIS);
	}
};
#endif /* !TRAININGSTATE_H */