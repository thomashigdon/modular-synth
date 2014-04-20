#ifndef PrintOutput_hh
#define PrintOutput_hh


#include "Sink.hh"

class PrintOutput : public Sink
{
public:
	PrintOutput(Synth* synth);
	void Run();
};

#endif //PrintOutput_hh
