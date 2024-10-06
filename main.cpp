#include "pixel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>

void add_pixel(std:: vector <Pixel*> &pixel_list, float r, float g, float b, int x, int y)
{
    Pixel *p = (Pixel*) malloc(sizeof(Pixel));
    p->r=r;
    p->g=g;
    p->b=b;
    p->x=x;
    p->y=y;
    pixel_list.push_back(p);
    free(p);
}


int main(int argc, char*argv[])
{
    std::ifstream in;
    in.open(argv[1],std::ios::in);
    if (!in.is_open())
    {
        std::cout <<"file cant be opened"<< std::endl;
    }
    else
    {
        std::string input;
        int i = 0;
        int x = 0;
        int y = 0;
        float r = 0;
        float g = 0;
        float b = 0;
        while (!in.eof())
        {
            i=0;
            std::getline(in, input);
            //std::cout <<input<< std::endl;
            float data = 0;
            int prev_find = 0;
            int last_find = input.find(",");
            while (last_find!=std::string::npos)
            {
                i++;
                data = std::stof (input.substr(prev_find, last_find-prev_find));
                if (i == 1)
                {
                    x = data;
                }
                else if (i == 2)
                {
                    y = data;
                }
                else if (i == 3)
                {
                    r = data;
                }
                else if (i == 4)
                {
                    g = data;
                }
                //std::cout << input.substr(prev_find, last_find-prev_find) << std::endl;
                std::cout << data << ", " << i << std::endl;
                prev_find = last_find+1;
                last_find = input.find(",", last_find+1);
                
            }
            i++;
            data = std::stof (input.substr(prev_find, input.length()+1-prev_find));
            b = data;
            //std::cout << input.substr(prev_find, input.length()+1-prev_find) << std::endl;
            std::cout << data << ", " << i << std::endl;
            std::cout << x << ", " << y << ", " << r << ", " << g << ", " << b << ", " << std::endl;
            add_pixel(pixel_list, r, g, b, x, y);
        }
        in.close();
        //std::cout << pixel_list[1].r << std::endl;
    }
    return 0;
}