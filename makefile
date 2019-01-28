IDIR =include 
CXX=g++ 
CC=gcc
CXXFLAGS= -I$(IDIR) -I./lib  -std=c++11 -w

SRCDIR=src
ODIR=build
TARGET=bin/kmeans
LDIR=-L../lib

LIBS=-lm 


_DEPS= kmeans.h cluster.h
	
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = kmeans.o cluster.o

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRCDIR)/%.cpp 
	@mkdir -p $(ODIR)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
$(ODIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(OBJ)
	@echo "\n\n\n Linking ...." 
	g++ -o $@ $^ $(CXXFLAGS) $(LIBS) 


.PHONY: clean

clean:
	@echo " Cleaning ....";
	rm -rf $(ODIR) bin/
