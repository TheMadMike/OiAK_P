CC=g++
CFLAGS= -std=c++17 -Wall -g
SOURCES= src/*.cpp
TARGET= oiak

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

