#ifndef Attenuator_hh
#define Attenuator_hh
#include "NodeList.hh"
#include "Node.hh"
#include "Source.hh"

#include <vector>

class Attenuator : public Node
{
public:
	Attenuator(Synth* synth, 
        int level,
        float attenuation,
        NodeList input,
        NodeList output);

	void Run(VvFloat buf, int numSamples);

private:
  float mAttenuation;
};
#endif


