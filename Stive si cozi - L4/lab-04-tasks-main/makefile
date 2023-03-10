CC = gcc
CFLAGS = -g -Wall
FLAGS = -g -Wall -o
EXECUTABLE = lab
BUILD_FOLDER_PATH = ./build/

build: build-dir
	cd ./src &&\
	make build-lib

test: build
	cd ./tests &&\
	make test

test-stack: build
	cd ./tests &&\
	make test-stack

test-queue: build
	cd ./tests &&\
	make test-queue

test-task: build
	cd ./tests &&\
	make test-task

build-dir: clean
	mkdir $(BUILD_FOLDER_PATH)

single-run: build-dir
	cd ./src &&\
	make run

clean:
	rm -rf $(BUILD_FOLDER_PATH)
