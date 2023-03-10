CXX = g++
CXXFLAGS = -g -Wall
EXECUTABLE = tests
SHARED-LIB = lab4
BUILD_FOLDER_PATH = ../build/
LIB_PATH = ../src/libs/
TEST_LIB_PATH = ./libs
BASE_SOURCE_TEST = main.cpp test-utils.cpp

build:
	$(CXX) $(CXXFLAGS) *.cpp -l$(SHARED-LIB) -I$(LIB_PATH) -I$(TEST_LIB_PATH) -L../build -o $(BUILD_FOLDER_PATH)$(EXECUTABLE)

build-queue:
	$(CXX) $(CXXFLAGS) $(BASE_SOURCE_TEST) queue_tests.cpp -l$(SHARED-LIB) -I$(LIB_PATH) -I$(TEST_LIB_PATH) -L../build -o $(BUILD_FOLDER_PATH)$(EXECUTABLE)

build-stack:
	$(CXX) $(CXXFLAGS) $(BASE_SOURCE_TEST) stack_tests.cpp -l$(SHARED-LIB) -I$(LIB_PATH) -I$(TEST_LIB_PATH) -L../build -o $(BUILD_FOLDER_PATH)$(EXECUTABLE)

build-task:
	$(CXX) $(CXXFLAGS) $(BASE_SOURCE_TEST) test-cerinta.cpp -l$(SHARED-LIB) -I$(LIB_PATH) -I$(TEST_LIB_PATH) -L../build -o $(BUILD_FOLDER_PATH)$(EXECUTABLE)


test: build
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(BUILD_FOLDER_PATH) &&\
	$(BUILD_FOLDER_PATH)$(EXECUTABLE)

test-stack: build-stack
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(BUILD_FOLDER_PATH) &&\
	$(BUILD_FOLDER_PATH)$(EXECUTABLE)

test-queue: build-queue
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(BUILD_FOLDER_PATH) &&\
	$(BUILD_FOLDER_PATH)$(EXECUTABLE)

test-task: build-task
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(BUILD_FOLDER_PATH) &&\
	$(BUILD_FOLDER_PATH)$(EXECUTABLE)

