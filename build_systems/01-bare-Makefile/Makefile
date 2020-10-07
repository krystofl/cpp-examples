BUILD   = build
INCLUDE = include
SRC     = src

EXEC_NAME = $(BUILD)/my_exec

CPP = g++

# C++17: -std=c++17
# C++20: -std=c++2a
CPPFLAGS = -std=c++2a -Wall -Wno-deprecated -Wno-unknown-pragmas -Wno-reorder \
	 -Wno-unused-local-typedefs -I$(INCLUDE)

# the default target is the first one in the file - so it should be all
# $^ means all the dependencies. In this case, build/penguin.o src/main.cpp
all: build/penguin.o src/main.cpp
	$(CPP) $(CPPFLAGS) $^ -o $(EXEC_NAME)

# $@ means the target name - in this case build/penguin.o
build/penguin.o: $(INCLUDE)/Penguin.h $(SRC)/Penguin.cpp
	$(CPP) $(CPPFLAGS) -c $(SRC)/Penguin.cpp -o $@

clean:
	rm $(BUILD)/*
