#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int get_base(int size_of_tree) {
  int start = 1;
  int layers = 4;
  int i = 0;
  int base = 0;
  int sub = 2;

  while (i < size_of_tree) {
    if (i % 2 == 0 && i != 0) {
      sub += 2;
    }
    i++;

    base = ((layers - 1) * 2) + start;
    start = base - sub;
    layers++;

  }
  return base;
}

int get_starting_spaces(int base, int size_of_tree) {
  int space_needed = size_of_tree / 2;

  int y = ((base - size_of_tree) / 2) + space_needed; 
  return y;
}

void print_characters(int amount_of, char character) {
  int i = amount_of;
  while (i > 0) {
    printf("%c", character);
    i--;
  }
  if (character != ' ') {
    printf("\n");
  }
}

void print_triangle(int layer_size, int amount_of_spaces, int amount_of_asterisk) {
  int i = 0;

  while (i < layer_size) {
    print_characters(amount_of_spaces, ' ');
    print_characters(amount_of_asterisk, '*');

    amount_of_spaces -= 1;
    amount_of_asterisk += 2;
    i++;
  }
}

int get_spaces(int space_tracker) {
  int increment_by = 0;
  if (space_tracker >= 2 && space_tracker % 2) {
      increment_by++;
    } else if (space_tracker<2) {
      increment_by++;
    } 
 
  return increment_by;    

}
int get_asteriks(int space_tracker) {
  int increment_by = 0;
      if (space_tracker >= 1 && space_tracker % 2) {
      increment_by += 2;
    } 
  return increment_by;    
}

void print_base(int base, int size_of_tree) {
  int i = size_of_tree;
  int x = (base - size_of_tree);
  int answer1 = x / 2;
  int answer1_remainder = x % 2;
  
   if (answer1_remainder > 0) {
        answer1 += 1;
    }
  
  while(i > 0) {
    print_characters(answer1, ' ');
    print_characters(size_of_tree, '|');
    i--;
  }

}

void print_tree(int size_of_tree) {
  int i = size_of_tree;
  int layer_size = 4;
  int amount_of_asteriks = 1;
  int amount_of_spaces = get_starting_spaces(get_base(size_of_tree), size_of_tree);
  int amount_of_spaces_add = 1;
  int amount_of_asteriks_add = 4;
  int space_tracker = 0;
  

  while (i > 0) {
    print_triangle(layer_size, amount_of_spaces, amount_of_asteriks);
    amount_of_asteriks_add += get_asteriks(space_tracker);
    amount_of_spaces_add += get_spaces(space_tracker);
    amount_of_spaces -= amount_of_spaces_add;
    amount_of_asteriks += amount_of_asteriks_add;
    layer_size++;
    i--;
    space_tracker++;
  }

  print_base(get_base(size_of_tree), size_of_tree);

}

int main(int argc, char **argv) {
 int user_given = atoi(argv[1]);
 print_tree(user_given);
 
 return argc;
}