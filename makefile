#
#

CXX=g++

CFLAGS=-Wall -Wextra -Wpedantic -O2 -Iinclude `pkg-config --cflags opencv4`
LDFLAGS=`pkg-config --libs opencv4`

SRCDIR=src
BINDIR=bin
INTDIR=$(BINDIR)/int

BIN=$(BINDIR)/laplacian-test

laplacian-test.cpp=$(SRCDIR)/laplacian-test.cpp
laplacian-test.o=$(INTDIR)/laplacian-test.o

laplacian.cpp=$(SRCDIR)/laplacian.cpp
laplacian.o=$(INTDIR)/laplacian.o

$(BIN): init $(laplacian.o) $(laplacian-test.o)
	$(CXX) $(laplacian-test.o) $(laplacian.o) $(LDFLAGS) -o $(BIN)

$(laplacian.o): $(laplacian.cpp)
	$(CXX) $(laplacian.cpp) $(CFLAGS) -c -o $(laplacian.o)

$(laplacian-test.o): $(laplacian-test.cpp)
	$(CXX) $(laplacian-test.cpp) $(CFLAGS) -c -o $(laplacian-test.o)

init:
	mkdir -p $(BINDIR) $(INTDIR)

clean:
	rm -rf $(INTDIR) $(BINDIR)

