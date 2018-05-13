#include "racs.h"
#include "amoba.h"
#include "graphics.hpp"
using namespace genv;

racs::racs(int x, int y, int sx, int sy, int sr, Amoba* parent): Widget(x,y,sx,sy)
{
    _parent=parent;
    ki_van="nincs";
    _ki="";
    p1=false;
    p2=false;
    n=false;
    hasznalt=false;
    _sr=sr;
}

void racs::draw()
{
    if(ki_van=="nincs")
    {
        gout<<move_to(_x,_y)<<color(45, 20, 10)<<box(_sx,_sy);
        gout<<move_to(_x+1,_y+1)<<color(0, 0, 0)<<box(_sx-2,_sy-2);
    }
    if(ki_van=="Player1 jon")
    {
        gout<<move_to(_x,_y)<<color(255,255,255)<<box(_sx,_sy);
        gout<<move_to(_x+1,_y+1)<<color(255,0,0)<<box(_sx-2,_sy-2);
    }
    if(ki_van=="Player2 jon")
    {
        gout<<move_to(_x,_y)<<color(255,255,255)<<box(_sx,_sy);
        gout<<move_to(_x+1,_y+1)<<color(0,0,244)<<box(_sx-2,_sy-2);
    }
}

void racs::handle(genv::event ev)
{
    if(!hasznalt)
    {
        ki_van=_parent->getkovi();
        if(ki_van=="Player1 jon")
            _ki="1";
        if(ki_van=="Player2 jon")
            _ki="2";
        _parent->uj_lepes(_sr);
        hasznalt=true;
    }
}

bool racs::focuszos()
{
    _focusable=false;
}

string racs:: getKi()
{
    return _ki;
}

string racs::gettext()
{
    return ki_van;
}
