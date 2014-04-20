#ifndef Source_hh
#define Source_hh
#include "Node.hh"
#include "Node.hh"

class Source : public Node
{
public:
	Source(Synth* synth, Node *port);
	const Node* OutputNode() const;
	Node* OutputNode();

private:
	Node *mOutputNode;
};

#endif

