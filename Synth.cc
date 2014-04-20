#include "Synth.hh"
#include "Node.hh"

#include <vector>
#include <iostream>

using namespace std;

Synth::Synth(Params params)
	: mParams(params),
		mBufferNumber(0),
		mNextNodeId(0)
{
}

const Params& Synth::Parameters() const
{
	return mParams;
}

const int Synth::BufferNumber() const
{
	return mBufferNumber;
}

const int Synth::NextNodeId()
{
	return mNextNodeId++;
}

void Synth::AddNode(Node *node)
{
	if (node->NodeLevel() > mvvNodes.size())
	{
		cerr << "Level " << node->NodeLevel() << " higher than " 
				 << "mvvNodes size (" << mvvNodes.size() << ")" << endl;
		return;
	}

	if (node->NodeLevel() == mvvNodes.size())
	{
    vector<Node *> tempVec(1, node);
		// have to push a vector of one Node
		mvvNodes.push_back(tempVec);
	}
	else
	{
		mvvNodes[node->NodeLevel()].push_back(node);
	}
}

void Synth::Run(VvFloat buf, int numSamples)
{
  for (vector<Node *>::iterator iter = mvvNodes[0].begin();
      iter != mvvNodes[0].end();
      iter++)
  {
    (*iter)->Run(buf, numSamples);
  }
  SampleNumber() += numSamples;
}

void Synth::IncBufferNumber()
{
	mBufferNumber++;
}

const int Synth::SampleNumber() const
{
  return mSampleNumber;
}

int& Synth::SampleNumber()
{
  return mSampleNumber;
}
