#ifndef Synth_hh
#define Synth_hh

#include "Params.hh"
#include "Types.hh"

#include <vector>

class Node;

class Synth
{
public:
	Synth(Params params);

	void Run(VvFloat buf, int numSamples);
	void AddNode(Node *node);

	const Params& Parameters() const;
	const int BufferNumber() const;
	const int NextNodeId();
  const int SampleNumber() const;
  int& SampleNumber();
	
private:

	void IncBufferNumber();

	// the first index is the level (Sink = 0, first source = size of outer std::vector
	// second index is the Node within
	std::vector< std::vector<Node *> >  mvvNodes;
	Params mParams;
	int mBufferNumber;
	int mNextNodeId;
  int mSampleNumber;
};

#endif
