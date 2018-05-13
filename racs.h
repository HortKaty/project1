#ifndef RACS_H_INCLUDED
#define RACS_H_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"
#include "amoba.h"

class Amoba;
class racs : public Widget
{
protected:
    Amoba _parent;
    std::string ki_van;
    bool p1;
    bool p2;
    bool n;

public:
    racs(int x, int y, int sx, int sy, int kx, int ky, string ki, Amoba* parent);
    void handle(genv::event ev);
    void drow();
    std::string gettext();

};

#endif // RACS_H_INCLUDED
