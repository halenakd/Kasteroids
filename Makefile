# -g flags para debug
# -Wall ativar warnings

CXXFLAGS=-I/usr/include/SDL2 -D_REENTRANT -g -gstabs -Wall -std=c++17
LDFLAGS=-pthread -lSDL2main -lSDL2 


all: sdl.o window.o point2.o vetor.o shape.o polygon.o quadrilateral.o triangle.o circle.o objeto.o ship.o asteroid.o projectile.o
	# Compile and link the source and object files into a final executable binary
	$(CXX) $(CXXFLAGS) main.cpp sdl.o window.o point2.o vetor.o shape.o polygon.o quadrilateral.o triangle.o circle.o objeto.o ship.o asteroid.o projectile.o $(LDFLAGS)

%.o: %/%.cpp %/%.h
	$(CXX) $(CXXFLAGS) -g -c %/%.cpp $(LDFLAGS)

clean:
	# remove all binary object files
	rm -f *.o 
	# remove binary executable
	rm -f a.out
	# remove doc directory
	rm -fR doc

doc:
	# create output directory doc
	mkdir -p doc
	# run the doxygen executable, generating html ouput documentation 
	doxygen
