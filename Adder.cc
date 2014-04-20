#include "Adder.hh"
#include "Types.hh"
#include <vector>
#include <iostream>

using namespace std;

Adder::Adder(Synth* synth,
             int level,
             NodeList input,
             NodeList output)
 : Node(synth, level, input, output)
{
}

void Adder::Run(VvFloat buf, int numSamples)
{
  if (mInputNodes.size() == 0)
  {
    ZeroBuf(buf, numSamples);
    return;
  }

  mInputNodes[0]->Run(buf, numSamples);
  for (int k = 1; k < mInputNodes.size(); k++)
  {
    mInputNodes[k]->Run(tempBuf, numSamples);
    for (int i = 0; i < buf.size(); i++)
    {
      for (int j = 0; j < numSamples; j++)
      {
        buf[i][j] += tempBuf[i][j];
      }
    }
  }
}
