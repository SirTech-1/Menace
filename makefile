# Var definitions

export MAKEFLAGS=-j3

CXX = g++ -O3

CC_FLAGS = -W -Wall -fno-rtti -ansi -Wshadow -Wextra -m64 -std=c++17 -msse -flto=auto
LD_FLAGS = -Wl,--no-as-needed -lpthread -m64 -std=c++17 -msse -flto=auto

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

all: Menace MenaceTesting
	chmod 755 test/EloRegressionTest/eloRegressionTest.sh
	chmod 755 test/EloRegressionTest/cutechess-cli.sh
	chmod 755 test/EloRegressionTest/cutechess-cli

Menace: $(OBJ_FILES)
	$(CXX) -o $@ $^ $(LD_FLAGS) $(EXTRA_FLAGS)

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_TEST_FILES) rm -rf $(OBJ_FILES)

MenaceTesting: $(OBJ_TEST_FILES)
	$(CXX) -o $@ $^ $(LD_FLAGS) $(EXTRA_FLAGS)

obj/%.o: test/%.cpp
	$(CXX) $(CC_FLAGS) -I $(SRC_DIR) -c -o $@ $<
