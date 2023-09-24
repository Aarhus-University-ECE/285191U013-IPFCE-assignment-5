#pragma once
#include <stdbool.h>

typedef struct point {
  int x;
  int y;
} point;

// add your definition (struct) of circle here. You need to call it "circle"

void five_circles(circle c[]);
bool circle_is_valid(const circle *c);
void translate(circle *c, const point *p);
