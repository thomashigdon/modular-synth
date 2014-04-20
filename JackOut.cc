#include "JackOut.hh"
#include "Synth.hh"

#include <algorithm>
#include <iostream>

using namespace std;

int JackOut::audioCallback(jack_nframes_t nframes,
        audioBufVector inBufs,
        audioBufVector outBufs,
        midiBufVector)
{
  mpSynth->Run(outBufs, nframes);
  //return 0 on success
  return 0;
}

JackOut::JackOut(Synth* synth)
: JackCpp::AudioIO("jackcpp-test", 0,2),
  mpSynth(synth)
{
    //we have 16 total input and output ports that we could have
    reserveOutPorts(16);
    addOutPort("left");
    addOutPort("right");
    start();
    connectToPhysical(0,0);
    connectToPhysical(1,1);
    /* constructor:
       Names JACK client "jackcpp-test"
       creates 2 in ports named input0 and input1
       creates 2 out ports named output0 and output1
       */
}

JackOut::~JackOut()
{
  disconnectOutPort(1);
  close();
}
