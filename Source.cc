#include "Source.hh"

Source::Source(Synth* synth, Node *port)
	: Node(synth),
		mOutputNode(port)
{
}

Node* Source::OutputNode()
{
	return mOutputNode;
}

const Node* Source::OutputNode() const
{
	return mOutputNode;
}

