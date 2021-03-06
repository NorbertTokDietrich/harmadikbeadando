#ifndef PARENTWINDOW_HPP_INCLUDED
#define PARENTWINDOW_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>

class ParentWidget; //forward deklar?ci?: ez a t?pus l?tezni fog, de m?g nincs

class ParentWindow{
protected:
    int _X, _Y;
    std::vector<ParentWidget*> w;
    bool everythingok1=true;
    bool everythingok2=true;
    int _first_tank=0;
    int _second_tank=0;
    bool started=false;
    int _order=1;
public:
    ParentWindow(int X, int Y);
    void registerwidget(ParentWidget *w);
    void event_loop();
    void settanklocationinvector(int a, int b);
    int returnthosevalues1();
    int returnthosevalues2();
    void addtoorder();
    int returnorder();
};

#endif // PARENTWINDOW_HPP_INCLUDED
