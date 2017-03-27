CC=g++
CPPFLAGS=-g -Wall -Ijackcpp/include
LDFLAGS = -Ljackcpp -ljackcpp -ljack -lrt -lpthread
OBJS = main.o \
 Adder.o \
 Attenuator.o \
 JackOut.o \
 Generator.o \
 SineGenerator.o \
 SquareGenerator.o \
 Synth.o \
 Node.o \
 NodeList.o

all: synth

synth: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

clean:
	rm -f main \
		main.o \
		Attenuator.o \
		Synth.o \
		Node.o \
		Generator.o \
		SineGenerator.o \
		PrintOutput.o \
		AudioOutput.o \
		JackOut.o \
		NodeList.o \
		SquareGenerator.o \
		Adder.o
