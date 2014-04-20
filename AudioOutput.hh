#ifndef AudioOutput_hh
#define AudioOutput_hh

#include <pulse/simple.h>
#include "Sink.hh"

class AudioOutput : public Sink
{
public:
	AudioOutput(Synth* synth);
	~AudioOutput();
	void Run();
	uint8_t FloatToUint8(float num);
private:
	pa_sample_spec mPa_sample_spec;
	pa_simple* mPa_simple;
};

#endif //AudioOutput_hh
