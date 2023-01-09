# Var definitions

export MAKEFLAGS=-j3

CXX = g++ -O3
#CXX = clang++-3.6

CXX_FLAGS = -W -Wall -Wcast-qual -std=c++14 -flto
LD_FLAGS = -Wall -Wcast-qual -std=c++14 -lpthread -flto

ifeq ($(NO_POPCNT), 1)
    EXTRA_FLAGS += -DNO_POPCNT
    NO_POPCNT = 0
endif


SRC_FILES := $(wildcard src/*.cpp)

TEST_FILES := $(wildcard test/*.cpp)
TEST_FILES += $(sort $(SRC_FILES) $(TEST_FILES))
TEST_FILES := $(filter-out src/Main.cpp, $(TEST_FILES))

OBJ_FILES := $(addprefix obj/,$(notdir $(SRC_FILES:.cpp=.o)))
OBJ_TEST_FILES := $(addprefix obj/,$(notdir $(TEST_FILES:.cpp=.o)))

SRC_DIR = $(shell pwd)/src

all: Menace

Menace: $(OBJ_FILES)
	$(CXX)  -o $@ $^ $(LD_FLAGS) $(EXTRA_FLAGS)

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_TEST_FILES) rm -rf $(OBJ_FILES)

MenaceTesting: $(OBJ_TEST_FILES)
	$(CXX) -o $@ $^ $(LD_FLAGS) $(EXTRA_FLAGS)

obj/%.o: test/%.cpp
	$(CXX) $(CC_FLAGS) -I $(SRC_DIR) -c -o $@ $<
