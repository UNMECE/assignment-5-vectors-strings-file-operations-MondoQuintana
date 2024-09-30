#include "pixel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>

/*void add_pixel(std:: vector <Pixel*> &pixel_list, float r, float g, float b, int x, int y)
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
*/

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
        while (!in.eof())
        {
            std::getline(in, input);
            int prev_find = 0;
            int last_find = input.find(",");
            std::string pixel_data;
            while (last_find!=std::string::npos)
            {
                
                input.substr(prev_find, last_find-prev_find);

            }
            
            //std::cout <<input<< std::endl;
        }
        in.close();
    }
    
    

    return 0;
}