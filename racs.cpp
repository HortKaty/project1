#include "racs.h"
#include "amoba.h"
#include "graphics.hpp"
using namespace genv;

racs::racs(int x, int y, int sx, int sy, int kx, int ky, string ki, Amoba* parent): Widget(x,y,sx,sy)
{
    _parent=parent;
    ki_van="nincs";
    ki="";
}

void racs::draw()
{
    if(n)
    {
        gout<<move_to(_x,_y)<<color(45, 20, 10)<<box(_sx,_sy);
        gout<<move_to(_x+1,_y+1)<<color(0, 0, 0)<<box(_sx-2,_sy-2);
    }
    if(p1)
    {
        gout<<move_to(_x,_y)<<color(255,255,255)<<box(_sx,_sy);
        gout<<move_to(_x+1,_y+1)<<color(47, 120, 10)<<box(_sx-2,_sy-2);
    }
    if(p2)
    {
        gout<<move_to(_x,_y)<<color(255,255,255)<<box(_sx,_sy);
        gout<<move_to(_x+1,_y+1)<<color(45, 20, 190)<<box(_sx-2,_sy-2);
    }
}

void racs::handle()
{
    if (ki_van="Player1" && ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
        {
            p1 = true;
            ki="1";
        }
    if (ki_van="Player2" && ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
        {
            p2 = true;
            ki="2";
        }
    if (ki_van="nincs" && ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
        {
            n = true;
            ki="";
        }
}

string racs::gettext()
{
    return ki_van;
}
