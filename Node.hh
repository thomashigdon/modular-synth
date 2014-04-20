#ifndef Node_hh
#define Node_hh
#include "Params.hh"
#include "Synth.hh"
#include "NodeList.hh"
#include "Types.hh"
#include <jackaudioio.hpp>

#include <vector>

class Node
{
  public:
    Node(Synth* synthPtr,
        int level,
        NodeList inputnodes,
        NodeList outputnodes);
    ~Node();

    virtual void Run(VvFloat buf,
        int numSamples) = 0;
    const Synth* MySynth() const;

    const unsigned int NodeLevel() const;
    void ZeroBuf(VvFloat buf, int numSamples);

  protected:
    NodeList mInputNodes;
    NodeList mOutputNodes;

    VvFloat tempBuf;

  private:
    Synth* mpSynth;
    unsigned int mNodeId;
    unsigned int mNodeLevel;
};
#endif
