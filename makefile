CXX = g++
CC = gcc
CFLAGS = -g -Wall -O2

SRC = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
OBJ = $(SRC:.cpp=.o)
INCLUDE = -I./src/ -Ithirdparty/lua/ -Ithirdparty/spdlog/include/
TARGET = projectforge
LINKERLIBS = ./bin/liblua.a ./bin/libspdlog.a -lpthread -ldl

.PHONY: all clean

all: libs dir build

dir:
	mkdir -p bin

libs:
	cd thirdparty/lua && make
	cp thirdparty/lua/liblua.a ./bin/liblua.a

	cd thirdparty/spdlog && mkdir -p build && cd build && cmake .. && make
	cp thirdparty/spdlog/build/libspdlog.a ./bin/libspdlog.a

build: $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o bin/$(TARGET) $(LINKERLIBS)

%.o: %.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ) bin/$(TARGET)
	cd thirdparty/lua && make clean