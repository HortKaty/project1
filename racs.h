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
    string ki_van;

public:
    racs(int x, int y, int sx, int sy, Amoba* parent);
    void handle(genv::event ev);
    void drow();
    string gettext();

};

#endif // RACS_H_INCLUDED
