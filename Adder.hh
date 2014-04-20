#ifndef Adder_hh
#define Adder_hh
#include "NodeList.hh"
#include "Node.hh"
#include "Source.hh"

#include <vector>

class Adder : public Node
{
  public:
    Adder(Synth* synth,
        int level,
        NodeList input,
        NodeList output);

    void Run(VvFloat buf, int numSamples);

  private:


};
#endif

