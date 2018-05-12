#ifndef GOMB_H_INCLUDED
#define GOMB_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class GombBox: public Widget
{
protected:
    bool selected;
    bool lenyomva;
    bool lenyomva_regi;

public:
    GombBox(int x, int y, int _sx, int _sy);
    virtual void draw();
    virtual void handle(genv::event ev);
    bool le_van_e_nyomva();
    void katt();
};

#endif // GOMB_H_INCLUDED
