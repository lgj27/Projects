# Makefile for version2
TARGET = version4

# files
CSRCS	:= 	$(wildcard src/*.cpp) $(wildcard lib/*.cpp)
COBJS	:=	$(CSRCS:.cpp=.o)
INCLUDE	:= include

# tools
CXX		:= g++
RM		:= rm -f

.PHONY: all
all:	$(TARGET)

$(TARGET):	$(COBJS)
	$(CXX) -o $@ $^

%.o:	%.cpp
	$(CXX) -c -I$(INCLUDE) -o $@ $<

.PHONY: run
run:	$(TARGET)
	./$(TARGET)

clean:
	$(RM) $(TARGET) $(COBJS)
