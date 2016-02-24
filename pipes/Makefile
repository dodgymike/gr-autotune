# object files have corresponding source files
CXX=gcc
COMPILER_FLAGS= -g
INCLUDE= 
LIBS=

EXEC= autotune

$(EXEC): pipe-based-autotune.c
	$(CXX) $(COMPILER_FLAGS) pipe-based-autotune.c -o $(EXEC) $(LIBS)

clean:
	rm -f $(EXEC)

