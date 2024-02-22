COMPILER=cc
FLAGS=-O3 -Wall -Wextra
libs_dep=libdata.a libgravity.a
libs_arg=-ldata -lgravity

exec.out: main.c $(libs_dep)
	$(COMPILER) main.c -o ../exec.out -I. -L. $(FLAGS) -lraylib -lm $(libs_arg)

data.o: data.c
	$(COMPILER) $(FLAGS) data.c -o data.o

gravity.o: gravity.c
	$(COMPILER) $(FLAGS) gravity.c -o gravity.o

libdata.a: data.o 
	ar ruv libdata.a data.o

libgravity.a: gravity.o 
	ar ruv libgravity.a gravity.o
