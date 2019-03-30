// File name: ExtremeC_examples_chapter5_5.c
// Description: Rectangle class in C

#include <stdio.h>

typedef struct {
  int width, length;
} rect_t;

int rect_area(rect_t* rect) {
  return rect->width * rect->length;
}

int main(int argc, char** argv) {
  rect_t r;
  r.width = 10;
  r.width = 25;
  int area = rect_area(&r);
  printf("Area: %d\n", area);
  return 0;
}
