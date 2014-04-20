#include "SineGenerator.hh"
#include "NodeList.hh"

#include <math.h>

#include <iostream>

using namespace std;

SineGenerator::SineGenerator(Synth* synth,
                             int level,
														 float amplitude,
														 float frequency,
														 NodeList output)
	: Generator(synth, level, amplitude, frequency, output)
{
}

float SineGenerator::FunctionGenerate(int sampleNumber, int sampleRate)
{
		return Amplitude()
					 * sin(sampleNumber * 2 * M_PI * Frequency()/sampleRate);
}
