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
   // bool starts;
    bool van_nyertes;
    std::string ki_jon;
    std::string nyertes;
    StaticTextBox *k;
    StaticTextBox *p1;
    StaticTextBox *p2;

public:
    Amoba();
    void uj_lepes(int sorszam);
    std::string getkovi();

};


#endif // AMOBA_H_INCLUDED
