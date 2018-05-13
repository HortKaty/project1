#include "graphics.hpp"
#include "racs.h"
#include "amoba.h"

using namespace genv;

Amoba::Amoba()
{
    gout.open(700,700);
    k= new StaticTextBox(50,50,100,40, "Player1 jon");
    p1= new StaticTextBox(50,300,100,40, "Player1:");
    p2= new StaticTextBox(50,450,100,40, "Player2:");
    widgets.push_back(k);
    widgets.push_back(p1);
    widgets.push_back(p2);
    lepesszam=0;
    for(unsigned int i=0; i<30; i++)
        for(unsigned int j=0; j<30; j++)
        {
            racs *uj= new racs(50+j*10, 50+i*10, 10, 10, j, i, this);
            racsok.push_back(uj);
            widgets.push_back(uj);
        }
    start=false;
}
void Amoba::uj_lepes()
{

}

bool Amoba::start()
{

}

string Amoba::getkovi()
{
    return ki_jon;
}
