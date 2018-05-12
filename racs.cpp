#include "racs.h"
#include "amoba.h"
#include "graphics.hpp"
using namespace genv;

racs::racs(int x, int y, int sx, int sy, Amoba* parent): Widget(x,y,sx,sy)
{
    _parent=parent;
    ki_van="";
}

void racs::draw()
{
    if(ki_van="")
    {
        gout<<move_to(_x,_y)<<color(45, 20, 10)<<box(_sx,_sy);
        gout<<move_to(_x+1,_y+1)<<color(45, 20, 10)<<box(_sx-2,_sy-2);
    }
    if(ki_van="Player1")
    {
        gout<<move_to(_x,_y)<<color(255,255,255)<<box(_sx,_sy);
        gout<<move_to(_x+1,_y+1)<<color(47, 120, 10)<<box(_sx-2,_sy-2);
    }
    if(ki_van="Player2")
    {
        gout<<move_to(_x,_y)<<color(255,255,255)<<box(_sx,_sy);
        gout<<move_to(_x+1,_y+1)<<color(45, 20, 190)<<box(_sx-2,_sy-2);
    }
}

void racs::handle()
{

}

string racs::gettext()
{
    return ki_van;
}