#pragma once
#ifndef LOADINGSTATE_H
#define LOADINGSTATE_H

class Chatbot;
class LoadingState
{
protected:

public:
	LoadingState() {
		std::cout << "OnState State Initialized" << std::endl;
	}

	void training(Chatbot* ins)
	{
		// train
		//ins->setState(LOADING);
	}
	void loading(Chatbot* ins, WordManager manager) 
	{
		//load stuff then go to listening
		//ins->structureManager.LoadStructures();
		//new WordManager("dictNoDef.txt");
		//ins->wordManager = manager;
		//ins->setState(LISTENING);
	}
	void listening(Chatbot* ins) 
	{
		//ins->setState(LISTENING);
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
#endif /* !LOADINGSTATE_H */