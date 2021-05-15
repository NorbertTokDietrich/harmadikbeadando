#include "parentwindow.hpp"
#include "graphics.hpp"
#include "parentwidget.hpp"

using namespace genv;
using namespace std;

ParentWindow::ParentWindow(int X, int Y):_X(X),_Y(Y)
{
    gout.open(_X,_Y);
    gout<<move_to(0,0)<<color(0,0,0)<<box(_X,_Y);
    gout<<font("LiberationSans-Regular.ttf",20);
}

void ParentWindow::registerwidget(ParentWidget * pw)
{
    w.push_back(pw);
}

void ParentWindow::event_loop()
{
    event ev;
    int focus=-1;
    while(gin>>ev && ev.keycode!=key_escape)
    {
        if(everythingok)
        {
            int check=-1;
            gout<<move_to(0,0)<<color(119,119,119)<<box(_X,_Y);
            if(ev.type==ev_mouse)
            {
                for(size_t i=0; i<w.size(); i++)
                {
                    if(w[i]->is_clicked(ev.pos_x, ev.pos_y))
                    {
                        focus=i;
                    }
                }
            }
            for(ParentWidget * pw : w)
            {
                pw->draw(0, ev);
            }
            if (focus!=-1)
            {
                w[focus]->action(ev);
                w[focus]->draw(1,ev);
            }
            w[_first_tank]->action(ev);
            w[_second_tank]->action(ev);

            /*if(ev.type==ev.timer)
            {
                w[_first_tank]->draw(ev);
                w[_second_tank]->draw(ev);
            }*/

            if(ev.type==ev_mouse)
            {
                for (size_t i=0; i<w.size(); i++)
                {
                    if (w[i]->is_clicked(ev.pos_x, ev.pos_y))
                    {
                        check = i;
                    }
                }
            }
            if(check==-1)
            {
                for (ParentWidget * pw : w)
                {
                    pw->draw(0, ev);
                }
            }
        }
        else
        {
            gout<<move_to(0,0)<<color(119,119,119)<<box(_X,_Y);
            gout << font("LiberationSans-Regular.ttf",30);
            gout<<move_to(300,200)<<color(255,255,255)<<text("GAME OVER");
        }
        gout << refresh;
    }
}

void ParentWindow::setok()
{
    everythingok=false;
}

int ParentWindow::returnok()
{
    return everythingok;
}

void ParentWindow::settanklocationinvector(int a, int b)
{
    _first_tank=a;
    _second_tank=b;
}

int ParentWindow::returnthosevalues1()
{
    return _first_tank;
}

int ParentWindow::returnthosevalues2()
{
    return _second_tank;
}
