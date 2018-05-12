#include "window.h"
using namespace genv;

void Window::event_loop()
{
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
}
