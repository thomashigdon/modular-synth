#include "PrintOutput.hh"

#include <iostream>

PrintOutput::PrintOutput(Synth* synth)
	: Sink(synth)
{
}

void PrintOutput::Run()
{
	int additive_factor = 
			MySynth()->BufferNumber() * MySynth()->Parameters().BufSize;
	for (int i = 0; i < InputPort().Bufsize(); i++)
	{
		std::cout << i 
							<< ": " 
							<< InputPort().Buffer()[i] + additive_factor  
							<< std::endl;
	}
}
