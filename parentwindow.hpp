#ifndef PARENTWINDOW_HPP_INCLUDED
#define PARENTWINDOW_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>

class ParentWidget; //forward deklaráció: ez a típus létezni fog, de még nincs

class ParentWindow{
protected:
    int _X, _Y;
    std::vector<ParentWidget*> w;
    bool everythingok=true;
    int _first_tank=0;
    int _second_tank=0;
public:
    ParentWindow(int X, int Y);
    void registerwidget(ParentWidget *w);
    void event_loop();
    void setok();
    int returnok();
    void settanklocationinvector(int a, int b);
    int returnthosevalues1();
    int returnthosevalues2();
};

#endif // PARENTWINDOW_HPP_INCLUDED
