#ifndef Port_hh
#define Port_hh

class Port
{
public:
	Port(int bufsize);
	~Port();

	float* Buffer();
	int Bufsize();

private:
	int mBufsize;
	float *mpBuffer;
};


#endif 
