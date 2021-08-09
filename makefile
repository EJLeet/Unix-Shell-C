CC=gcc 
CFLAGS=
DEPS = include.h stack.h 								# include directory
OBJ = calc.o time.o path.o sys.o put.o get.o main.o 	# source directory

%.o: %.c $(DEPS) 										# create .o files after compiling .c and .h files
	$(CC) -c -o $@ $< $(CFLAGS)

shell: $(OBJ) 											# create out file
	$(CC) -o $@ $^ $(CFLAGS) 