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
#include "tank.hpp"
#include <iostream>
#include <cmath>

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
    Button * fire;
    Arena * area;
    Tank * tankleft;
    Tank * tankright;
    int heightleft=Y-100;
    int heightright=Y-200;
    int lx;
    int ly;
    int rx;
    int ry;
    int xleft;
    int xright;
    int talaltleft;
    int talaltright;
public:
    MyWindow();
    bool returnok()
    {
        return true;
    }
    void firsttankleft()
    {
        if(returnok())
        {
            tankleft->goleft();
            refreshleft();
        }
    }
    void firsttankright()
    {
        if(returnok())
        {
            tankleft->goright();
            refreshleft();
        }
    }
    void secondtankleft()
    {
        if(returnok())
        {
            tankright->goleft();
            refreshright();
        }
    }
    void secondtankright()
    {
        if(returnok())
        {
            tankright->goright();
            refreshright();
        }
    }
    void tankfire()
    {
        int order=returnorder();
        if(order%2==1)
        {
            addtoorder();
            tankleft->setshoot1();
            tankleft->setinitialspeed(strength1->number());
            tankleft->setangle(degree1->number());
            tankleft->setwinddirection(wind->returndirection());
            tankleft->setwindspeed(wind->returnspeed());
            tankleft->shoot1();
        }
        else
        {
            addtoorder();
            tankright->setshoot2();
            tankright->setinitialspeed(strength1->number());
            tankright->setangle(degree2->number());
            tankright->setwinddirection(wind->returndirection());
            tankright->setwindspeed(wind->returnspeed());
            tankright->shoot2();
        }
        wind->windchange();
    }
    void refreshleft()
    {
        tankleft->setangle(degree1->number());
        tankleft->refreshpositionleft();
    }
    void refreshright()
    {
        tankright->setangle(degree2->number());
        tankright->refreshpositionright();
    }
};

MyWindow::MyWindow():ParentWindow(800,600)
{
    strength1=new NumberSet(this, 20, Y-60, 60, 40, 1, 1, 4, [&]()
    {
        refreshleft();
    });
    degree1=new NumberSet(this, 100, Y-60, 60, 40, 15, 0, 60, [&]()
    {
        refreshleft();
    });
    strength2=new NumberSet(this, X-160, Y-60, 60, 40, 1, 1, 4, [&]()
    {
        refreshright();
    });
    degree2=new NumberSet(this, X-80, Y-60, 60, 40, 15, 0, 60, [&]()
    {
        refreshright();
    });
    wind=new Wind(this, X/2-120, 30, 240, 70);
    left1=new Button(this, 180, Y-60, 40, 40, "<", [&]()
    {
        firsttankleft();
    });
    left2=new Button(this, X-280, Y-60, 40, 40, "<", [&]()
    {
        secondtankleft();
    });
    right1=new Button(this, 240, Y-60, 40, 40, ">", [&]()
    {
        firsttankright();
    });
    right2=new Button(this, X-220, Y-60, 40, 40, ">", [&]()
    {
        secondtankright();
    });
    fire=new Button(this, 370, Y-60, 60, 40, "Fire", [&]()
    {
        tankfire();
    });
    area=new Arena(this, 10, 10, 10, 10, heightleft, heightright);
    tankleft=new Tank(this, 100, heightleft-50, 10, 10, 15, 1, 2);
    tankright=new Tank(this, X-200, heightright-50, 10, 10, 15, 2, -3);
    for(size_t i=0; i<w.size(); i++)
    {
        if(w[i]==tankleft)
        {
            talaltleft=i;
        }
    }
    for(size_t i=0; i<w.size(); i++)
    {
        if(w[i]==tankright)
        {
            talaltright=i;
        }
    }
    settanklocationinvector(talaltleft,talaltright);
}

int main()
{
    MyWindow *win=new MyWindow;
    win->event_loop();
    return 0;
}
