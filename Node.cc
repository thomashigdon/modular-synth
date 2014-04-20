#include "Node.hh"
#include "Params.hh"
#include "Synth.hh"
#include "NodeList.hh"
#include <iostream>

using namespace std;

Node::Node(Synth* synthPtr,
           int level,
           NodeList inputnodes,
           NodeList outputnodes)
: mInputNodes(inputnodes),
  mOutputNodes(outputnodes),
  mpSynth(synthPtr),
  mNodeId(mpSynth->NextNodeId()),
  mNodeLevel(level)
{
  cout << "Node constructor called" << endl;
  tempBuf.resize(4);
  for (int i = 0; i < 4; i++)
  {
    tempBuf[i] = new float[2048];
  }

}

Node::~Node()
{
  for (int i = 0; i < 4; i++)
  {
    delete[] tempBuf[i];
  }
}

const Synth* Node::MySynth() const
{
  return mpSynth;
}

const unsigned int Node::NodeLevel() const
{
  return mNodeLevel;
}

void Node::ZeroBuf(VvFloat buf, int numSamples)
{
  for (unsigned int i = 0; i < buf.size(); i++)
  {
    for (int j = 0; j < numSamples; j++)
    {
      buf[i][j] = 0;
    }
  }
}
