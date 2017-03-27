#include <jackaudioio.hpp>

class Synth;

class JackOut: public JackCpp::AudioIO
{
  public:
    virtual int audioCallback(jack_nframes_t nframes,
                              audioBufVector inBufs,
                              audioBufVector outBufs);

    JackOut(Synth* synth);
    ~JackOut();
private:
    Synth *mpSynth;
};
