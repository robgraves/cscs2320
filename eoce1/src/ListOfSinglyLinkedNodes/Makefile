CXXFLAGS = -fPIC -Wall
INC = -I ../../inc
AR = ar
CXX = g++
SRC = $(shell /bin/ls -1 *.cc 2>/dev/null)
OBJ = $(SRC:.cc=.o)
LIB = $(shell /bin/pwd | /bin/sed 's/^.*\///')
NAME = $(shell echo "$(LIB)" | /usr/bin/tr '[:lower:]' '[:upper:]')
all: intro $(SRC) $(OBJ) lib

intro:
ifneq ($(MAKECMDGOALS),debug)
	@printf "Building the \033[1;36m$(NAME)\033[0m library\n"
	@printf "=======================================\n"
endif

debug: CXXFLAGS += -DDEBUG -g
debug: DEBUG = debug
debug: $(SRC) $(OBJ) lib

.cc.o:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[\033[0;33mCXX\033[0m]   %-20s ... " "$<"
	@$(CXX) $(CXXFLAGS) $(INC) -c $< 2>> ../../errors && echo "\033[0;32mOK\033[0m" || echo "\033[0;31mFAIL\033[0m"
else
	$(CXX)  $(CXXFLAGS) $(INC) -c $<
endif

lib:
ifneq ($(MAKECMDGOALS),debug)
	@printf "       %-20s ... " "lib$(LIB).{a,so}"
	@$(AR) rcs ../../lib/lib$(LIB).a $(OBJ) 2>> ../../errors && $(CXX) -shared -o ../../lib/lib$(LIB).so -Wl,--whole-archive ../../lib/lib$(LIB).a -Wl,--no-whole-archive && echo "\033[1;32mSUCCESS\033[0m" || echo "\033[1;31mFAIL\033[0m"
	@echo
else
	$(AR)  rcs ../../lib/lib$(LIB).a $(OBJ)
	$(CXX) -shared -o ../../lib/lib$(LIB).so -Wl,--whole-archive ../../lib/lib$(LIB).a -Wl,--no-whole-archive
endif

clean:
	@rm -f .*.sw[op] *.save* *~ *.o $(OBJ) core ../../errors
