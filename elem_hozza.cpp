#include "elem_hozza.h"

Elem_Hozza::Elem_Hozza(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    selected=false;
}

void Elem_Hozza::draw()
{
    if(selected)
    {
        gout<<move_to(_x, _y)<<color(200,100,100)<<box(_sx,_sy);
        gout<<move_to(_x+3, _y+3)<<color(200,100,100)<<box(_sx-6,_sy-6);
    }
    else
    {
        gout<<move_to(_x, _y)<<color(200,100,100)<<box(_sx,_sy);
        gout<<move_to(_x+3, _y+3)<<color(200,100,100)<<box(_sx-6,_sy-6);
    }


}

void Elem_Hozza::handle(event ev)
{

}

std::string Elem_Hozza::settext()
{

}
