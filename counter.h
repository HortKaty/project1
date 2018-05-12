#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class CountBox : public Widget
{
protected:
    bool selected;
    std::string szoveg;
    int szam;
    int _Flim;
    int _Alim;
    bool vanLim;
public:
    CountBox(int x, int y, int sx, int sy, std::string szov);
    CountBox(int x, int y, int sx, int sy, std::string szov, int Flim, int Alim);
    virtual void draw() ;
    virtual void handle(genv::event ev);
};

#endif // COUNTER_H_INCLUDED
