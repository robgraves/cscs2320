LIBS =  -lListOfDoublyLinkedNodes -lListOfSinglyLinkedNodes -lList -lDoublyLinkedNode -lSinglyLinkedNode -lNode
CXXFLAGS = -Wall -static -L../../lib $(LIBS)
INC = -I ../../inc/
CXX = g++ $(INC)
SRC = $(shell /bin/ls -1 *.cc 2>/dev/null)
BIN = $(SRC:.cc=)
BINPATH = ../../bin
all: $(SRC) $(BIN)

debug: CXX += -DDEBUG -g
debug: DEBUG = debug
debug: $(SRC) $(BIN)

.cc:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[B]    %-20s ... " "$<"
	@$(CXX) -o $(BINPATH)/$@ $< $(CXXFLAGS) && echo "OK" || echo "FAIL"
else
	$(CXX) -o $(BINPATH)/$@ $< $(CXXFLAGS)
endif

scripts:
	@/bin/cp -f *.sh $(BINPATH)/

clean:
	@rm -f .*.sw[op] *.swp *.save* *~ *.o $(BINPATH)/$(BIN) core
