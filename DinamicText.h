#ifndef DINAMICTEXT_H_INCLUDED
#define DINAMICTEXT_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class DinamicTextBox : public Widget {
protected:
    bool selected;
    std::string szoveg;
public:
    DinamicTextBox(int x, int y, int sx, int sy, std::string szov);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual std::string gettext();
};

#endif // DINAMICTEXT_H_INCLUDED
