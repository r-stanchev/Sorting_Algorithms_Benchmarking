# code details

EXE_DIR = sort
EXE = $(EXE_DIR)

SRC= main.c algorithms.c print_data.c generate_array.c

# generic build details

CC=      cc
COPT=    -g -std=c99
CFLAGS= -g

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
		$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
		$(CC) $(OBJ) $(CFLAGS)  -o $(EXE)

# clean up compilation

clean:
		rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c algorithms.c
algorithms.o:   algorithms.c algorithms.h
print_data.o:   print_data.c print_data.h
generate_array.o:	generate_array.c generate_array.h
