#ifndef ELEM_HOZZA_H_INCLUDED
#define ELEM_HOZZA_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

using namespace genv;

class Elem_Hozza: public Widget
{
protected:
    bool selected;

public:
    Elem_Hozza(int x, int y, int _sx, int _sy);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual std::string settext();
};

#endif // ELEM_HOZZA_H_INCLUDED
