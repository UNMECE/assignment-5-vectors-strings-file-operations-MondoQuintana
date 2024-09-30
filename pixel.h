#ifndef PIXEL_H
#define PIXEL_H

#include <vector>

struct _pixel
{
  float r;
  float g;
  float b;
  int x;
  int y;
};
typedef struct _pixel Pixel;

std::vector <Pixel *> pixel_list;
void add_pixel(std:: vector <Pixel*> &pixel_list, float r, float g, float b, int x, int y);

#endif 
