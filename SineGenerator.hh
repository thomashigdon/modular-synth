#ifndef SineGenerator_hh
#define SineGenerator_hh

#include "Generator.hh"
#include "NodeList.hh"

#include <vector>

class SineGenerator : public Generator
{
public:
	SineGenerator(Synth* synth, 
                int level, 
                float amplitude, 
                float frequency, 
                NodeList output);
	float FunctionGenerate(int sampleNumber, int sampleRate);

private:

};	
#endif
