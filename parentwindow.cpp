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
    gin.timer(20);
    while(gin>>ev && ev.keycode!=key_escape)
    {
        int x1=w[_first_tank]->returnx();
        int y1=w[_first_tank]->returny();
        int x2=w[_second_tank]->returnx();
        int y2=w[_second_tank]->returny();
        int lx1=w[_first_tank]->returnlx();
        int ly1=w[_first_tank]->returnly();
        int rx1=w[_second_tank]->returnrx();
        int ry1=w[_second_tank]->returnry();
        if(lx1>=x2 && lx1<=(x2+100) && ly1>=(y2-15))
        {
            everythingoksecond=false;
        }
        if(rx1>=x1 && rx1<=(x1+100) && ry1>=(y1-15))
        {
            everythingokfirst=false;
        }

        int check=-1;
        if(ev.type==ev_mouse)
        {
            for(size_t i=0; i<w.size(); i++)
            {
                if(w[i]->is_clicked(ev.pos_x, ev.pos_y))
                {
                    focus=i;
                }
            }
            if (focus!=-1)
            {
                w[focus]->action(ev);
            }
            w[_first_tank]->action(ev);
            w[_second_tank]->action(ev);
            for (size_t i=0; i<w.size(); i++)
            {
                if (w[i]->is_clicked(ev.pos_x, ev.pos_y))
                {
                    check = i;
                }
            }
        }

        if(ev.type==ev_timer)
        {
            if(everythingokfirst && everythingoksecond)
            {
                gout<<move_to(0,0)<<color(119,119,119)<<box(_X,_Y);
                for(ParentWidget * pw : w)
                {
                    pw->draw(0, ev);
                }
                if (focus!=-1)
                {
                    w[focus]->draw(1,ev);
                }
                w[_first_tank]->action(ev);
                w[_second_tank]->action(ev);
                w[_first_tank]->draw(0,ev);
                w[_second_tank]->draw(0,ev);
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
                if(everythingokfirst)
                {
                    gout<<move_to(0,0)<<color(119,119,119)<<box(_X,_Y);
                    for(ParentWidget * pw : w)
                    {
                        pw->draw(0, ev);
                    }
                    gout << font("LiberationSans-Regular.ttf",30);
                    gout<<move_to(300,150)<<color(255,255,255)<<text("GAME OVER");
                    gout<<move_to(170,200)<<color(255,255,255)<<text("THE WINNER IS PLAYER ONE!");
                    gout<<move_to(160,250)<<color(255,255,255)<<text("DON'T WORRY PLAYER TWO, ");
                    gout<<move_to(130,300)<<color(255,255,255)<<text("NEXT TIME YOU'LL FAIR BETTER! :)");
                }
                else
                {
                    gout<<move_to(0,0)<<color(119,119,119)<<box(_X,_Y);
                    for(ParentWidget * pw : w)
                    {
                        pw->draw(0, ev);
                    }
                    gout << font("LiberationSans-Regular.ttf",30);
                    gout<<move_to(300,150)<<color(255,255,255)<<text("GAME OVER");
                    gout<<move_to(180,200)<<color(255,255,255)<<text("THE WINNER IS PLAYER TWO!");
                    gout<<move_to(160,250)<<color(255,255,255)<<text("DON'T WORRY PLAYER ONE, ");
                    gout<<move_to(130,300)<<color(255,255,255)<<text("NEXT TIME YOU'LL FAIR BETTER! :)");
                }
            }
        }
        gout << refresh;
    }
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
