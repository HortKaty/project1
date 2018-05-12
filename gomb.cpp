#include "gomb.h"
#include "graphics.hpp"

using namespace genv;

GombBox::GombBox(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    lenyomva=false;
    lenyomva_regi=false;
}

void GombBox::draw()
{
    if(!lenyomva)
    {
        gout<<move_to(_x+6,_y+6)<<color(68, 39, 36)<<box(_sx,_sy);
        gout<<move_to(_x,_y)<<color(200,100,100)<<box(_sx,_sy);
        gout<< move_to(_x+_sx/2-gout.twidth("Csatol")/2, _y+_sy/2+(gout.cascent()+gout.cdescent())/2)<<color(0,0,0)<<text("Csatol");
    }
    else
    {
        gout<<move_to(_x,_y)<<color(0,0,0)<<box(_sx,_sy);
        gout<<move_to(_x+6,_y+6)<<color(200,100,100)<<box(_sx,_sy);
        gout<< move_to((_x+6)+_sx/2-gout.twidth("Csatol")/2, (_y+6)+_sy/2+(gout.cascent()+gout.cdescent())/2)<<color(0,0,0)<<text("Csatol");
    }
}

void GombBox::handle(event ev)
{
    if(ev.type==ev_mouse && ev.pos_x>_x && ev.pos_x<_x+_sx && ev.pos_y>_y && ev.pos_y<_y+_sy && ev.button==btn_left)
    {
        lenyomva=true;
        lenyomva_regi=true;
    }
    if(ev.type==ev_mouse && ev.pos_x>_x && ev.pos_x<_x+_sx && ev.pos_y>_y && ev.pos_y<_y+_sy && ev.button==-btn_left)
    {
        lenyomva=false;
    }
}

bool GombBox::le_van_e_nyomva()
{
    return lenyomva_regi;
}
void GombBox::katt()
{
    lenyomva_regi=false;
}
