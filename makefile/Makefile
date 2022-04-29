MUDUO_DIRECTORY ?= $(HOME)/build/debug-install
#MUDUO_DIRECTORY ?= $(HOME)/build/install
MUDUO_INCLUDE = $(MUDUO_DIRECTORY)/include
MUDUO_LIBRARY = $(MUDUO_DIRECTORY)/lib
SRC = ../src

CXXFLAGS = -g -O0 -Wall -Wextra -Werror \
	   -Wconversion -Wno-unused-parameter \
	   -Wold-style-cast -Woverloaded-virtual \
	   -Wpointer-arith -Wshadow -Wwrite-strings \
	   -march=native -rdynamic \
	   -I$(MUDUO_INCLUDE)

LDFLAGS = -L$(MUDUO_LIBRARY) -lmuduo_net -lmuduo_base -lmuduo_http -lpthread -lrt

all: hmsPro
clean:
	rm -f hmsPro core

hmsPro: $(SRC)/HttpServer_test.cc
	g++ $(CXXFLAGS) -o $@ $^ $(LDFLAGS) `mysql_config --cflags --libs` 

.PHONY: all clean
