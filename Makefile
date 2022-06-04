CC=g++
CFLAGS= -std=c++17 -Wall
SOURCES= src/*.cpp
TARGET= oiak

all:
	$(CC) $(CLFAGS) $(SOURCES) -o $(TARGET)

