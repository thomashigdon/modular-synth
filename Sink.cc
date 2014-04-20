#include "Sink.hh"

Sink::Sink(Synth* synth)
	: Node(synth),
		mInputNode(synth->Parameters().BufSize)
{
}

Node& Sink::InputNode()
{
	return mInputNode;
}

const Node& Sink::InputNode() const
{
	return mInputNode;
}
