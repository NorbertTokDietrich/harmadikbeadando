#ifndef PARENTWINDOW_HPP_INCLUDED
#define PARENTWINDOW_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>

class ParentWidget; //forward deklar�ci�: ez a t�pus l�tezni fog, de m�g nincs

class ParentWindow{
protected:
    int _X, _Y;
    std::vector<ParentWidget*> w;
    bool everythingokfirst=true;
    bool everythingoksecond=true;
    int _first_tank=0;
    int _second_tank=0;
    bool started=false;
public:
    ParentWindow(int X, int Y);
    void registerwidget(ParentWidget *w);
    void event_loop();
    void settanklocationinvector(int a, int b);
    int returnthosevalues1();
    int returnthosevalues2();
};

#endif // PARENTWINDOW_HPP_INCLUDED
