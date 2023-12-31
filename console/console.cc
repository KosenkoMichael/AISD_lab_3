#define _HAS_STD_BYTE 0

#include <functions/algorithm.h>
#include "functions/graphics.h"

int main()
{
    // gm is Graphics mode which is a computer display 
    // mode that generates image using pixels. 
    // DETECT is a macro defined in "graphics.h" header file 
    int gd = DETECT, gm;
    // initgraph initializes the graphics system 
    // by loading a graphics driver from disk 
    char hui[1] = "";
    initgraph(&gd, &gm, hui);
    // line for x1, y1, x2, y2 
    //line(150, 150, 450, 150);
    line(5, 5, 5, 450);
    line(5, 450, 600, 450);

    getch();
    // closegraph function closes the graphics 
    // mode and deallocates all memory allocated 
    // by graphics system . 
    closegraph();
}