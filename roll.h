#ifndef ROLL_H_INCLUDED
#define ROLL_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>

using namespace std;

class RollBox: public Widget
{
protected:
    bool selected;
    bool gordul_e;
    bool kijelol;
    vector<string>v;
    int hely;
    int kihely;
public:
    RollBox(int x, int y, int _sx, int _sy, vector<string>_v);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual void settext(string text);
};

#endif // ROLL_H_INCLUDED
