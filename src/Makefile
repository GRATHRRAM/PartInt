COMPILER=cc
FLAGS=-O3 -Wall -Wextra -g
libs_dep=libstrc.a libgravity.a
libs_arg=-lstrc -lgravity

exec.out: ../main.c $(libs_dep)
	$(COMPILER) ../main.c -o ../exec.out -I. -L. $(FLAGS) -lraylib -lm $(libs_arg)

data.o: strc.c
	$(COMPILER) $(FLAGS) strc.c -o strc.o -c

gravity.o: gravity.c
	$(COMPILER) $(FLAGS) gravity.c -o gravity.o -c

libstrc.a: strc.o 
	ar ruv libstrc.a strc.o

libgravity.a: gravity.o 
	ar ruv libgravity.a gravity.o

clean: 
	rm -rf *.o *.a
