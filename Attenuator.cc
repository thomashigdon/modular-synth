#include "Attenuator.hh"
#include "Types.hh"
#include <vector>
#include <iostream>

using namespace std;

Attenuator::Attenuator(Synth* synth,
             int level,
             float attenuation,
             NodeList input,
             NodeList output)
	:	Node(synth, level, input, output),
    mAttenuation(attenuation)
{
}

void Attenuator::Run(VvFloat buf, int numSamples)
{
  if (mInputNodes.size() == 0)
  {
    ZeroBuf(buf, numSamples);
    return;
  }
      
  for (int k = 0; k < mInputNodes.size(); k++)
  {
    mInputNodes[k]->Run(buf, numSamples);
    for (int i = 0; i < buf.size(); i++)
    {
      for (int j = 0; j < numSamples; j++)
      {
        buf[i][j] *= mAttenuation;
        if (buf[i][j] > 1.0)
        { 
          buf[i][j] = 1.0;
        }
      }
    }
  }
}

