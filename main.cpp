#include "graphics.hpp"
#include "widgets.hpp"
#include "DinamicText.h"
#include "roll.h"
#include "gomb.h"
#include "counter.h"
#include <vector>
using namespace std;
using namespace genv;

void event_loop(vector<Widget*>& widgets)
{

}


int main()
{
    gout.open(600,600);
    vector<Widget*> w;
    vector<string> s;
    s.push_back("cica");
    s.push_back("kutya");
    s.push_back("ló");
    DinamicTextBox * b1 = new DinamicTextBox(10,10,200,60, "");
    RollBox * c1 = new RollBox(10,100,200,60, s);
    GombBox * d1 = new GombBox(250,200,200,60);
    w.push_back(b1);
    w.push_back(c1);
    w.push_back(d1);
    for (Widget * wg : w)
    {
        wg->draw();
    }
    gout << refresh;
    vector<Widget*> widgets;
    widgets=w;
    event ev;
    int focus = -1;
    while(gin >> ev )
    {
        if(ev.keycode==key_escape)
            break;
        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (size_t i=0; i<widgets.size(); i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    if (focus!=-1)
                    {
                        widgets[focus]->handle(ev);
                    }
                    focus = i;
                }
            }
        }
        if (focus!=-1)
        {
            widgets[focus]->handle(ev);
        }
        if(d1->le_van_e_nyomva())
            c1->settext(b1->gettext());
        d1->katt();
        for (Widget * w : widgets)
        {
            w->draw();
        }
        gout << refresh;
    };
    return 0;
}
