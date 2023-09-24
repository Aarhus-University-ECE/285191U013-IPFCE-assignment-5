#pragma once

typedef struct point {
  int x;
  int y;
} point;

// add your definition of circle here. You need top call it "circle"

void five_circles(circle c[]);
int circle_is_valid(const circle *c);
void translate(circle *c, const point *p);
