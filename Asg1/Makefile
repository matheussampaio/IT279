# "all" is name of the default target, running "make" without params would use it
all: default

# for C++, replace CC (c compiler) with CXX (c++ compiler) which is used as default linker
CC=$(CXX)

# tell which files should be used, .cpp -> .o make would do automatically
default: Asg1.o myArray.o
	g++ Asg1.cpp myArray.cpp
