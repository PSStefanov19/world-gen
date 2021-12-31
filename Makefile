# Include/ dir and obj/ dir
IDIR=include
ODIR=obj

# Compiler options and flags
CXX=g++

# Check if make is being ran on Windows or Unix
ifeq ($(OS),Windows_NT)
	CXXFLAGS=-I$(IDIR) -Iinclude/extras -Llib/
	OUT_EXT=exe
else
	CXXFLAGS=-I$(IDIR)
	OUT_EXT=out
endif

ERRFLAGS=-O3 -Wall -Wextra -Werror -g

# Put header files here
_DEPS=map.h
DEPS=$(patsubst %, $(IDIR)/%, $(_DEPS))

# Put cpp files but change extension to .o
_OBJ=main.o map.o
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

# Libraries
ifeq ($(OS),Windows_NT)
	LIBS=-lraylib -mwindows -lopengl32 -lgdi32 -lwinmm
else
	LIBS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

# Compile .cpp files to .o files
$(ODIR)/%.o: src/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(ERRFLAGS)

# Link .o files and make an executable in bin/ folder
main: $(OBJ)
	$(CXX) -o bin/$@.$(OUT_EXT) $^ $(CXXFLAGS) $(ERRFLAGS) $(LIBS)