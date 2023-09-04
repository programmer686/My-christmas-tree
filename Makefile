CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/home/docode/project -lmylibrary

all: my_christmas_tree

my_christmas_tree: my_christmas_tree.o 
	gcc $(CFLAGS) my_christmas_tree.o -o my_christmas_tree

my_christmas_tree.o: my_christmas_tree.c
	gcc $(CFLAGS) -c my_christmas_tree.c


clean:
	rm -f *.o my_christmas_tree

fclean: clean

re: fclean all
