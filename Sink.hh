#ifndef Sink_hh
#define Sink_hh
#include "Node.hh"

class Sink : public Node
{
public:
	Sink(Synth* synth);
	const Node& InputNode() const;
	Node& InputNode();
private:
	Node mInputNode;
};

#endif
