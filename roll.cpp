#include "graphics.hpp"
#include "roll.h"
#include <vector>

using namespace genv;

RollBox::RollBox(int x, int y, int sx, int sy, vector<string>_v)
    : Widget(x,y,sx,sy)
{
    selected=false;
    gordul_e=false;
    kijelol=false;
    v=_v;
    hely=0;
    kihely=0;
}

void RollBox::draw()
{
    if(selected)
    {
        gout<<move_to(_x, _y)<<color(200,100,100)<<box(_sx,_sy);
        gout<< move_to(_x+3, _y+3) << color(0,0,0) << box(_sx-6, _sy-6);
        gout<< move_to(_x+(_sx-_sx/4)/2-gout.twidth(v[hely])/2, _y+_sy/2+(gout.cascent()+gout.cdescent())/2)<<color(200,100,100)<<text(v[hely]);
        gout<<move_to(_x+_sx,_y)<< color(200,100,100) << box(-_sx/4, _sy);
        gout<<move_to(_x+_sx-3*(_sx/16), _y+3)<<color(0,0,0)<<line_to(_x+_sx-_sx/8,(_y+_sy)-3);
        gout<<move_to(_x+_sx-_sx/8,(_y+_sy)-3)<<color(0,0,0)<<line_to(_x+_sx-_sx/16,_y+3);
        if(gordul_e)
        {
            for(unsigned int i=0; i<v.size(); i++)
            {
                gout<<move_to(_x, _y+_sy+i*26)<<color(200,100,100)<<box(_sx, 26);
                if(!kijelol)
                {
                    gout<<move_to(_x+3, (_y+_sy+i*26)+3)<<color(0,0,0)<<box(_sx-5, 21);
                    gout<<move_to((_x+_sx/2)-gout.twidth(v[i])/2, _y+_sy+i*26+13+(gout.cascent()+gout.cdescent())/2)<<color(200,100,100)<<text(v[i]);
                }
                else
                {
                    if(i==kihely)
                    {
                        gout<<move_to(_x, _y+_sy+kihely*26)<<color(200,100,100)<<box(_sx, 26);
                        gout<<move_to((_x+_sx/2)-gout.twidth(v[kihely])/2, _y+_sy+i*26+13+(gout.cascent()+gout.cdescent())/2)<<color(0,0,0)<<text(v[kihely]);
                    }
                    else
                    {
                        gout<<move_to(_x+3, (_y+_sy+i*26)+3)<<color(0,0,0)<<box(_sx-5, 21);
                        gout<<move_to((_x+_sx/2)-gout.twidth(v[i])/2, _y+_sy+i*26+13+(gout.cascent()+gout.cdescent())/2)<<color(200,100,100)<<text(v[i]);
                    }
                }
            }

        }
        else
        {
            for(unsigned int i=0; i<v.size(); i++)
            {
                gout<<move_to(_x, _y+_sy+i*26)<<color(0,0,0)<<box(_sx, 26);
            }
        }

    }
    else
    {
        gout<<move_to(_x, _y)<<color(255,255,255)<<box(_sx,_sy);
        gout<< move_to(_x+3, _y+3) << color(0,0,0) << box(_sx-6, _sy-6);
        gout<< move_to(_x+(_sx-_sx/4)/2-gout.twidth(v[hely])/2, _y+_sy/2+(gout.cascent()+gout.cdescent())/2)<<color(255,255,255)<<text(v[hely]);
        gout<<move_to(_x+_sx,_y)<< color(255,255,255) << box(-_sx/4, _sy);
        gout<<move_to(_x+_sx-3*(_sx/16), _y+3)<<color(0,0,0)<<line_to(_x+_sx-_sx/8,(_y+_sy)-3);
        gout<<move_to(_x+_sx-_sx/8,(_y+_sy)-3)<<color(0,0,0)<<line_to(_x+_sx-_sx/16,_y+3);
        gout<<move_to(_x, _y+_sy)<<color(0,0,0)<<box(_sx+4, v.size()*26+4);
    }
}

void RollBox::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
        selected = true;
    if (ev.type == ev_mouse && !is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
        selected = false;
    if (ev.type==ev_mouse && ev.pos_x<_x+_sx && ev.pos_x>_x+_sx-_sx/4 && ev.pos_y<_y+_sy && ev.pos_y>_y && ev.button==-btn_left)
        gordul_e=true;
    if (ev.type==ev_mouse && !(ev.pos_x<_x+_sx && ev.pos_x>_x && ev.pos_y>_y && ev.pos_y<_y+_sy+v.size()*26))
        gordul_e=false;
    bool egyiksincs=true;
    for(unsigned int i=0; i<v.size(); i++)
    {
        if(ev.type == ev_mouse && ev.pos_x>_x && ev.pos_x<_x+_sx && ev.pos_y>_y+_sy+i*26 && ev.pos_y<_y+_sy+(i+1)*26)
        {
            kijelol=true;
            kihely=i;
            egyiksincs=false;
            if(ev.button==btn_left)
            {
                hely=i;
                gordul_e=false;
            }
        }
        if(egyiksincs)
            kijelol=false;
    }
}

void RollBox::settext(string text)
{
    v.push_back(text);
}
