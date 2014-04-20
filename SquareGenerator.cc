#include "SquareGenerator.hh"
#include "NodeList.hh"

#include <math.h>

#include <iostream>

using namespace std;

SquareGenerator::SquareGenerator(Synth* synth,
                             int level,
														 float amplitude,
														 float frequency,
                             float dutyCycle,
														 NodeList output)
	: Generator(synth, level, amplitude, frequency, output),
    mDutyCycle(dutyCycle)
{
}

float SquareGenerator::FunctionGenerate(int sampleNumber, int sampleRate)
{
  int numSamples = sampleRate / Frequency();
  if (sampleNumber % numSamples < mDutyCycle * numSamples)
		return Amplitude();
  else
    return -Amplitude();
}

