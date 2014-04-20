#include "Port.hh"

Port::Port(int bufsize)
{
	mBufsize = bufsize;
	mpBuffer = new float[bufsize]; 
}

Port::~Port()
{
	delete[] mpBuffer;
}

float* Port::Buffer()
{
	return mpBuffer;
}

int Port::Bufsize()
{
	return mBufsize;
}
