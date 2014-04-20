#ifndef Generator_hh
#define Generator_hh
#include "NodeList.hh"
#include "Types.hh"
#include "Node.hh"
#include "Source.hh"

#include <vector>

class Generator : public Node
{
  public:
    Generator(Synth* synth,
        int level,
        float amplitude,
        float frequency,
        NodeList output);
    ~Generator();
    virtual float FunctionGenerate(int sampleNumber, int sampleRate) = 0;


    void Run(VvFloat buf, int numSamples);

    const float& Frequency() const;
    float& rFrequency();

    const float& Amplitude() const;
    float& rAmplitude();

    const int SamplesInCycle() const;

    float* Buffer();

  private:
    float* mWaveBuf;
    int mSamplesInCycle;
    float mAmplitude;
    float mFrequency;
    int mBufOffset;

};
#endif
