CXX=g++
CFLAGS=-g -w -std=c++11
target=RenderDemo
all:$(target)

$(target):RenderDemo.o
	$(CXX) $(CFLAGS) -o RenderDemo RenderDemo.o 
RenderDemo.o:RenderDemo.cpp
	$(CXX) $(CFLAGS) RenderDemo.cpp -c

.PHONY:clean tags
clean:
	-rm -f *.o
	-rm -f $(target)
	-rm -f tags
tags:
	ctags -R *
