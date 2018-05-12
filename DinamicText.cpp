#include "DinamicText.h"
#include "graphics.hpp"
using namespace genv;

DinamicTextBox::DinamicTextBox(int x, int y, int sx, int sy, std::string _szoveg)
    : Widget(x,y,sx,sy)
{
    selected=false;
    szoveg=_szoveg;
}

void DinamicTextBox::draw()
{
    if(selected)
    {
        gout << move_to(_x, _y) << color(200,100,100) << box(_sx, _sy);
        gout << move_to(_x+4, _y+4) << color(0,0,0) << box(_sx-8, _sy-8);
        gout<< move_to(_x+_sx/2-gout.twidth(szoveg)/2, _y+_sy/2+(gout.cascent()+gout.cdescent())/2)<<color(200,100,100)<<text(szoveg);
    }
    else
    {
        gout << move_to(_x, _y) << color(255,255,255) << box(_sx, _sy);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_sx-4, _sy-4);
        gout<< move_to(_x+_sx/2-gout.twidth(szoveg)/2, _y+_sy/2+(gout.cascent()+gout.cdescent())/2)<<color(255,255,255)<<text(szoveg);

    }
}

void DinamicTextBox::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
        selected = true;
    if (ev.type == ev_mouse && !is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
        selected = false;
    if(selected==true)
    {
        if(gout.twidth(szoveg)<_sx-20)
            if(ev.type==ev_key && ev.keycode>0 && ev.keycode<255 && ev.keycode!=114)
            {
                int szam;
                szam=ev.keycode;
                szoveg.push_back(szam);
            }
        if(ev.type==ev_key && ev.keycode==114)   //ez egy Easter Egg
            szoveg.push_back(108);
        if(ev.type==ev_key && ev.keycode==key_delete)
            if(szoveg.length()!=0)
                szoveg.pop_back();
    }
}

std::string DinamicTextBox::gettext()
{
    return szoveg;
}


