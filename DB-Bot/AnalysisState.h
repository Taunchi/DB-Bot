#pragma once
#ifndef ANALYSISSTATE_H
#define ANALYSISSTATE_H
#include "State.h"

class State;
class AnalysisState : public State
{
public:
	AnalysisState() {
		std::cout << "OnState State Initialized" << std::endl;
	}
	void loading(Chatbot* ins) {}
	void listening(Chatbot* ins) {}
	void speaking(Chatbot* ins) {}
	void analyzing(Chatbot* ins) {}
};
#endif /* !ANALYSISSTATE_H */