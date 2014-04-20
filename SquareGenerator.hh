#ifndef SquareGenerator_hh
#define SquareGenerator_hh

#include "Generator.hh"
#include "NodeList.hh"

#include <vector>

class SquareGenerator : public Generator
{
public:
	SquareGenerator(Synth* synth, 
                int level, 
                float amplitude, 
                float frequency, 
                float dutyCycle,
                NodeList output);
	float FunctionGenerate(int sampleNumber, int sampleRate);

private:
  float mDutyCycle;

};	
#endif

