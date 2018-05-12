#include "graphics.hpp"
#include "counter.h"
#include <sstream>

using namespace genv;

CountBox::CountBox(int x, int y, int sx, int sy, std::string _szoveg)
    : Widget(x,y,sx,sy)
{
    selected=false;
    szam=0;
    szoveg=_szoveg;
    vanLim=false;
}
CountBox::CountBox(int x, int y, int sx, int sy, std::string _szoveg, int Flim, int Alim)
    : Widget(x,y,sx,sy)
{
    selected=false;
    szam=0;
    szoveg=_szoveg;
    _Flim=Flim;
    _Alim=Alim;
    vanLim=true;
}
void CountBox::draw()
{
    if(selected)
    {
        gout<< move_to(_x, _y) << color(200,100,100) << box(_sx, _sy);
        gout<< move_to(_x+3, _y+3) << color(0,0,0) << box(_sx-6, _sy-6);
        gout<< move_to(_x+(_sx-_sx/4)/2-gout.twidth(szoveg)/2, _y+_sy/2+(gout.cascent()+gout.cdescent())/2)<<color(200,100,100)<<text(szoveg);
        gout<<move_to(_x+_sx,_y)<< color(200,100,100) << box(-_sx/4, _sy/2);
        gout<<move_to(_x+_sx,_y+_sy/2)<< color(200,100,100) << box(-_sx/4, _sy/2);
        gout<<move_to(_x+_sx-3*(_sx/16), (_y+_sy/2)-3)<<color(0,0,0)<<line_to(_x+_sx-_sx/8,_y+3);
        gout<<move_to(_x+_sx-_sx/8,_y+3)<<color(0,0,0)<<line_to(_x+_sx-_sx/16,(_y+_sy/2)-3);
        gout<<move_to(_x+_sx-3*(_sx/16), (_y+_sy/2)+3)<<color(0,0,0)<<line_to(_x+_sx-_sx/8,_y+_sy-3);
        gout<<move_to(_x+_sx-_sx/8,_y+_sy-3)<<color(0,0,0)<<line_to(_x+_sx-_sx/16,(_y+_sy/2)+3);
    }
    else
    {
        gout<< move_to(_x, _y) << color(255,255,255) << box(_sx, _sy);
        gout<< move_to(_x+3, _y+3) << color(0,0,0) << box(_sx-6, _sy-6);
        gout<< move_to(_x+(_sx-_sx/4)/2-gout.twidth(szoveg)/2, _y+_sy/2+(gout.cascent()+gout.cdescent())/2)<<color(255,255,255)<<text(szoveg);
        gout<<move_to(_x+_sx,_y)<< color(255,255,255) << box(-_sx/4, _sy/2);
        gout<<move_to(_x+_sx,_y+_sy/2)<< color(255,255,255) << box(-_sx/4, _sy/2);
        gout<<move_to(_x+_sx-3*(_sx/16), (_y+_sy/2)-3)<<color(0,0,0)<<line_to(_x+_sx-_sx/8,_y+3);
        gout<<move_to(_x+_sx-_sx/8,_y+3)<<color(0,0,0)<<line_to(_x+_sx-_sx/16,(_y+_sy/2)-3);
        gout<<move_to(_x+_sx-3*(_sx/16), (_y+_sy/2)+3)<<color(0,0,0)<<line_to(_x+_sx-_sx/8,_y+_sy-3);
        gout<<move_to(_x+_sx-_sx/8,_y+_sy-3)<<color(0,0,0)<<line_to(_x+_sx-_sx/16,(_y+_sy/2)+3);
    }
}

void CountBox::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
        selected = true;
    if (ev.type == ev_mouse && !is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
        selected = false;

    if((ev.type == ev_mouse && ev.pos_x<_x+_sx && ev.pos_x>_x+_sx-_sx/4 && ev.pos_y>_y && ev.pos_y<_y+_sy/2 && ev.button==-btn_left) || ev.keycode==key_up)
    {
        std::stringstream ss;
        if(vanLim)
        {
            if(szam<_Flim)
            {
                szam++;
                ss<<szam;
                ss>>szoveg;
                ss.clear();
            }
        }
        else
        {
            szam++;
            ss<<szam;
            ss>>szoveg;
            ss.clear();

        }


    }
    if((ev.type == ev_mouse && ev.pos_x<_x+_sx && ev.pos_x>_x+_sx-_sx/4 && ev.pos_y<_y+_sy && ev.pos_y>_y+_sy/2 && ev.button==-btn_left) || ev.keycode==key_down)
    {
        std::stringstream ss;

        if(vanLim)
        {
            if(szam>_Alim)
            {
                szam--;
                ss<<szam;
                ss>>szoveg;
                ss.clear();
            }
        }
        else
        {
            szam--;
            ss<<szam;
            ss>>szoveg;
            ss.clear();
        }
    }
    if(ev.keycode==key_pgup)
    {
        std::stringstream ss;
        if(vanLim)
        {
            if(szam<_Flim-10)
            {
                szam+=10;
                ss<<szam;
                ss>>szoveg;
                ss.clear();
            }
        }
        else
        {
            szam+=10;
            ss<<szam;
            ss>>szoveg;
            ss.clear();

        }
    }
    if(ev.keycode==key_pgdn)
    {
        std::stringstream ss;

        if(vanLim)
        {
            if(szam>_Alim+10)
            {
                szam-=10;
                ss<<szam;
                ss>>szoveg;
                ss.clear();
            }
        }
        else
        {
            szam-=10;
            ss<<szam;
            ss>>szoveg;
            ss.clear();
        }
    }
}
