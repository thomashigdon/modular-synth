#include "AudioOutput.hh"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#include <pulse/simple.h>
#include <pulse/error.h>

AudioOutput::AudioOutput(Synth* synth)
	: Sink(synth),
		mPa_simple(NULL)
{
	mPa_sample_spec.format = PA_SAMPLE_S16LE;
	mPa_sample_spec.rate = MySynth()->Parameters().SampleRate;
	mPa_sample_spec.channels = 1;

	int error;

	/* Create a new playback stream */
	if (!(mPa_simple = pa_simple_new(NULL,
													 		 		 "Synth",
																	 PA_STREAM_PLAYBACK,
																	 NULL,
																	 "playback",
																	 &mPa_sample_spec,
																	 NULL,
																	 NULL,
																	 &error))) {
		fprintf(stderr, __FILE__": pa_simple_new() failed: %s\n", pa_strerror(error));
	}
}

AudioOutput::~AudioOutput()
{
	int error;
	/* Make sure that every single sample was played */
	if (pa_simple_drain(mPa_simple, &error) < 0) {
		fprintf(stderr, __FILE__": pa_simple_drain() failed: %s\n", pa_strerror(error));
	}

	if (mPa_simple)
		pa_simple_free(mPa_simple);
		
}

uint8_t AudioOutput::FloatToUint8(float num)
{
	float positive_normalized = (num + 1) / 2;
	return floor(positive_normalized * 256);
}

void AudioOutput::Run()
{
	int error;
	ssize_t r = MySynth()->Parameters().BufSize;
	uint8_t buf[r];
	for (int i = 0; i < r; i++)
	{
		buf[i] = FloatToUint8(InputPort().Buffer()[i]);
		//printf("%f\n", InputPort().Buffer()[i]);
		//printf("%x\n", buf[i]);
	}
	if (pa_simple_write(mPa_simple, buf, r, &error) < 0) {
		fprintf(stderr, __FILE__": pa_simple_write() failed: %s\n", pa_strerror(error));
	}

}
