#include <vector>
#include <fstream>
#include "graphics.hpp"
#include "statictext.hpp"
#include "parentwidget.hpp"
#include "numberset.hpp"
#include "optionset.hpp"
#include "parentwindow.hpp"
#include "button.hpp"
#include "wind.hpp"
#include "arena.hpp"
#include <iostream>

using namespace genv;
using namespace std;

const int X=800;
const int Y=600;

class MyWindow:public ParentWindow
{
protected:
    NumberSet * strength1;
    NumberSet * degree1;
    NumberSet * strength2;
    NumberSet * degree2;
    Wind * wind;
    Button * left1;
    Button * left2;
    Button * right1;
    Button * right2;
    Button * fire1;
    Button * fire2;
    Arena * area;
public:
    MyWindow();
    void firsttankleft()
    {

    }
    void firsttankright()
    {

    }
    void secondtankleft()
    {

    }
    void secondtankright()
    {

    }
    void firstfire()
    {
        wind->windchange();
    }
    void secondfire()
    {
        wind->windchange();
    }
};

MyWindow::MyWindow():ParentWindow(800,600)
{
    strength1=new NumberSet(this, 20, Y-60, 60, 40, 1, 1, 10);
    degree1=new NumberSet(this, 100, Y-60, 60, 40, 15, 0, 90);
    strength2=new NumberSet(this, X-160, Y-60, 60, 40, 1, 1, 10);
    degree2=new NumberSet(this, X-80, Y-60, 60, 40, 15, 0, 90);
    wind=new Wind(this, X/2-120, 30, 240, 70);
    left1=new Button(this, 180, Y-60, 40, 40, "<", [&](){firsttankleft();});
    left2=new Button(this, X-280, Y-60, 40, 40, "<", [&](){secondtankleft();});
    right1=new Button(this, 240, Y-60, 40, 40, ">", [&](){firsttankright();});
    right2=new Button(this, X-220, Y-60, 40, 40, ">", [&](){secondtankright();});
    fire1=new Button(this, 300, Y-60, 60, 40, "Fire", [&](){firstfire();});
    fire2=new Button(this, X-360, Y-60, 60, 40, "Fire", [&](){secondfire();});
    area=new Arena(this, 10, 10, 10, 10, 500, 400);
}

int main()
{
    MyWindow *win=new MyWindow;
    win->event_loop();
    return 0;
}
