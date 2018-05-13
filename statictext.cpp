#include "statictext.h"
#include "graphics.hpp"
using namespace genv;

StaticTextBox::StaticTextBox(int x, int y, int sx, int sy, std::string _szoveg)
    : Widget(x,y,sx,sy)
{
    selected=false;
    szoveg=_szoveg;
}

void StaticTextBox::draw()
{
    if(selected)
    {
        gout << move_to(_x, _y) << color(255,255,255) << box(_sx, _sy);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_sx-4, _sy-4);
        gout<< move_to(_x+_sx/2-gout.twidth(szoveg)/2, _y+_sy/2+(gout.cascent()+gout.cdescent())/2)<<color(255,255,255)<<text(szoveg);
    }
    else
    {
        gout << move_to(_x, _y) << color(255,255,255) << box(_sx, _sy);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_sx-4, _sy-4);
        gout<< move_to(_x+_sx/2-gout.twidth(szoveg)/2, _y+_sy/2+(gout.cascent()+gout.cdescent())/2)<<color(255,255,255)<<text(szoveg);

    }
}

void StaticTextBox::handle(event ev)
{

}

std::string StaticTextBox::gettext()
{
    return szoveg;
}
void StaticTextBox::settext(std::string mire)
{
    szoveg=mire;
}
