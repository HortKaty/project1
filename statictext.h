#ifndef STATICTEXT_H_INCLUDED
#define STATICTEXT_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class StaticTextBox : public Widget {
protected:
    bool selected;
    std::string szoveg;
public:
    StaticTextBox(int x, int y, int sx, int sy, std::string szov);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual std::string gettext();
    void settext(std::string mire);
};

#endif // STATICTEXT_H_INCLUDED
