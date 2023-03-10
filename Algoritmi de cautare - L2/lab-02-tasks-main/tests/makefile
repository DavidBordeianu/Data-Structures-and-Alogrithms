CXX = g++
CXXFLAGS = -g -Wall
EXECUTABLE = tests
SHARED-LIB = lab2
BUILD_FOLDER_PATH = ../build/
LIB_PATH = ../src/libs/
TEST_LIB_PATH = ./libs
BASE_FILES = main.cpp

build:
	$(CXX) $(CXXFLAGS) merge_test_suite.cpp quick_test_suite.cpp $(BASE_FILES) -l$(SHARED-LIB) -I$(LIB_PATH) -I$(TEST_LIB_PATH) -L../build -o $(BUILD_FOLDER_PATH)$(EXECUTABLE)

build-bonus:
	$(CXX) $(CXXFLAGS) bonus_test_suite.cpp $(BASE_FILES) -l$(SHARED-LIB) -I$(LIB_PATH) -I$(TEST_LIB_PATH) -L../build -o $(BUILD_FOLDER_PATH)$(EXECUTABLE)

test-bonus: build-bonus
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(BUILD_FOLDER_PATH) &&\
	$(BUILD_FOLDER_PATH)$(EXECUTABLE)

test: build
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(BUILD_FOLDER_PATH) &&\
	$(BUILD_FOLDER_PATH)$(EXECUTABLE)
