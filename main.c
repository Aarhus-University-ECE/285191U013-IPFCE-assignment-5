#include <stdio.h>
#include <stdlib.h>

#include "circle.h"
#include "jollyjumper.h"

void print_circle(const circle c) {
  printf("p.x: %d, p.y: %d, r: %d\n", c.p.x, c.p.y, c.r);
}

int main() {
  // testing circles - make sure that you know how it works and what it is
  // supposed to print out
  circle c[5];
  five_circles(c);
  for (int i = 0; i < 5; i++) {
    print_circle(c[i]);
  }
  point p;
  p.x = 2;
  p.y = 2;
  translate(&c[1], &p);
  print_circle(c[1]);
  printf("Is valid? %d", circle_is_valid(&c[1]));

  // Answer to exercise 7.b
  int n = 0; // Number of numbers to read
  // Read-in n and check that is is OK

  int *numbers = malloc(sizeof(int) * n); // The numbers read

  // Read-in the n numbers in the array numbers

  if (is_jolly_jumber(numbers, n)) {
    printf("It is a Jolly Jumper");
  } else {
    printf("Not a Jolly Jumper");
  }
  return 0;
}
