#ifndef RACS_H_INCLUDED
#define RACS_H_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"
#include "amoba.h"

class Amoba;
class racs : public Widget
{
protected:
    Amoba* _parent;
    std::string ki_van;
    bool p1;
    bool p2;
    bool n;
    std::string _ki;
    bool hasznalt;
    int _sr;

public:
    racs(int x, int y, int sx, int sy, int sr, Amoba* parent);
    void handle(genv::event ev);
    void draw();
    std::string gettext();
    std::string getKi();
};

#endif // RACS_H_INCLUDED
