CC = g++
CFLAGS = -std=c++11 -Wall

all: main.cpp system_info_impl.cpp
	$(CC) $(CFLAGS) -o system_info main.cpp system_info_impl.cpp

clean:
	rm -f system_info
