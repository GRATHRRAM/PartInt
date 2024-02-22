COMPILER=cc
FLAGS=-O3 -Wall -Wextra

exec.out: main.c 
	$(COMPILER) main.c -o exec.out $(FLAGS) -lraylib -lm
