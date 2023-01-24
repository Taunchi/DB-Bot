#pragma once
#ifndef SPEAKINGSTATE_H
#define SPEAKINGSTATE_H
#include "State.h"

class SpeakingState : public State
{
public:
	SpeakingState() {
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
		//ins->setState(LISTENING);
	}
	void analyzing(Chatbot* ins)
	{
		//ins->setState(ANALYSIS);
	}
};
#endif /* !SPEAKINGSTATE_H */