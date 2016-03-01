# object files have corresponding source files
CXX=gcc
COMPILER_FLAGS= -g
INCLUDE= 
LIBS=-lpthread

EXEC= ook-decoder

$(EXEC): pipe-based-ook-decoder.c
	$(CXX) $(COMPILER_FLAGS) pipe-based-ook-decoder.c -o $(EXEC) $(LIBS)

clean:
	rm -f $(EXEC)

