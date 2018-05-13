#ifndef AMOBA_H_INCLUDED
#define AMOBA_H_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"
#include "statictext.h"
#include "racs.h"
#include <vector>
#include "window.h"

using namespace genv;

class racs;

class Amoba: public Window
{
protected:
    int lepesszam;
    vector<racs*>racsok;
    bool start;
    bool van_nyertes;
    std::string ki_jon;

public:
    Amoba();
    bool start(genv::event ev);
    void uj_lepes();
    std::string getkovi();
    StaticTextBox *k;
    StaticTextBox *p1;
    StaticTextBox *p2;
};


#endif // AMOBA_H_INCLUDED
