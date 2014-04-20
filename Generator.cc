#include "Generator.hh"
#include "Node.hh"

#include <math.h>
#include <iostream>

using namespace std;

Generator::Generator(Synth* synth,
    int level,
    float amplitude,
    float frequency,
    NodeList output)
: Node(synth, level, NodeList(), output),
  mAmplitude(amplitude),
  mFrequency(frequency),
  mBufOffset(0)
{
  cout << "Generator ctor called" << endl;
  int sampleRate = MySynth()->Parameters().SampleRate;
  mSamplesInCycle = floor(sampleRate / frequency);
  mWaveBuf = new float[mSamplesInCycle];
}

Generator::~Generator()
{
  delete[] mWaveBuf;
}

const int Generator::SamplesInCycle() const
{
  return mSamplesInCycle;
}

float* Generator::Buffer()
{
  return mWaveBuf;
}

const float& Generator::Frequency() const
{
  return mFrequency;
}

float& Generator::rFrequency()
{
  return mFrequency;
}

const float& Generator::Amplitude() const
{
  return mAmplitude;
}

float& Generator::rAmplitude()
{
  return mAmplitude;
}

void Generator::Run(VvFloat buf, int numSamples)
{
  int sampleRate = MySynth()->Parameters().SampleRate;
  //std::cout << "Amplitude: " << Amplitude() << std::endl;
  //std::cout << "Frequency: " << Frequency() << std::endl;
  //std::cout << "Samplerate: " << sampleRate << std::endl;
  for (unsigned int i = 0; i < buf.size(); i++)
  {
    for (int j = 0; j < numSamples; j++)
    {
      buf[i][j] = FunctionGenerate(j + MySynth()->SampleNumber(), sampleRate);
    }
  }

}
