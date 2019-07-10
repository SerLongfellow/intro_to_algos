
TARGET=max_subarray

INCDIRS=\
	-I. \
	-Irecursive \
	-Ibrute_force

CXXFLAGS+=\
		  -g \
		  -std=c++17 \
		  -Wall \
		  -Werror

CXXFLAGS+=$(INCDIRS)


SOURCES=$(shell find . -iname "*.cpp")
OBJS=$(SOURCES:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCDIRS) -o $@ $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS)
