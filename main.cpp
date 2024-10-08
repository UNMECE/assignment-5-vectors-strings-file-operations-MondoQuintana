#include "pixel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>

void add_pixel(std::vector <Pixel> &pixel_list, float r, float g, float b, int x, int y, int z)
{
    pixel_list.push_back(Pixel());
    pixel_list[z].r = r;
    pixel_list[z].g = g;
    pixel_list[z].b = b;
    pixel_list[z].x = x;
    pixel_list[z].y = y;
    std::cout <<"Pixel added at index "<<z<<"."<<std::endl;
    std::cout <<"Pixel r value at index "<<z<<": "<<pixel_list[z].r<<std::endl;
    std::cout <<"Pixel g value at index "<<z<<": "<<pixel_list[z].g<<std::endl;
    std::cout <<"Pixel b value at index "<<z<<": "<<pixel_list[z].b<<std::endl;
    std::cout <<"Pixel x value at index "<<z<<": "<<pixel_list[z].x<<std::endl;
    std::cout <<"Pixel y value at index "<<z<<": "<<pixel_list[z].y<<std::endl;
}

void average_colors(std::vector<Pixel> &pixel_list, int z)
{
    float avgR = 0;
    float avgG = 0;
    float avgB = 0;
    for (int i = 0; i < z; i++)
    {
        avgR += pixel_list[i].r;
        avgG += pixel_list[i].g;
        avgB += pixel_list[i].b;
    }
    std::cout<<"The average R value is: "<<avgR/z<<std::endl;
    std::cout<<"The average G value is: "<<avgG/z<<std::endl;
    std::cout<<"The average B value is: "<<avgB/z<<std::endl;
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
        int z = 0;
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
            std::cout << x << ", " << y << ", " << r << ", " << g << ", " << b << std::endl;
            add_pixel(pixel_list, r, g, b, x, y, z);
            z++;
        }
        in.close();
        //z = z-1;
        average_colors(pixel_list, z);
        //std::cout <<"Pixel r value at index "<<z-1<<": "<<pixel_list[z-1].r<<std::endl;
    }
    return 0;
}