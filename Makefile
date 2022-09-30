CC = g++
CFlags = -Wall -Werror -pedantic -std=c++14
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
DEPS = Triangle.h

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

all: TFractal

TFractal: TFractal.o Triangle.o
	$(CC) $(CFLAGS) -o TFractal $^ $(LIBS)

clean:
	rm *.o TFractal