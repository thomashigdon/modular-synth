#include "Synth.hh"
#include "SineGenerator.hh"
#include "SquareGenerator.hh"
#include "Adder.hh"
#include "Attenuator.hh"
#include "JackOut.hh"
#include <vector>
#include <unistd.h>

using namespace std;

int main()
{
  Params params;
  params.SampleRate = 48000;
  Synth synth(params);
  NodeList temp((Node *)0);
  SquareGenerator squaregen(&synth, 2, .25, 262, 0.5, NodeList(0));
  Attenuator attenuator(&synth, 1, 1, NodeList(&squaregen), NodeList(0)); 
  SineGenerator sinegen(&synth, 1, 0, 524, NodeList(0));
  NodeList adderInput(&sinegen, &attenuator);
  Adder adder(&synth, 0, adderInput, temp);
  synth.AddNode(&adder);
  synth.AddNode(&sinegen);
  synth.AddNode(&attenuator);
  synth.AddNode(&squaregen);

  JackOut out(&synth);

  sleep(10);

  return 0;
}
