#ifndef PARENTWINDOW_HPP_INCLUDED
#define PARENTWINDOW_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>

class ParentWidget; //forward deklaráció: ez a típus létezni fog, de még nincs

class ParentWindow{
protected:
    int _X, _Y;
    std::vector<ParentWidget*> w;
public:
    ParentWindow(int X, int Y);
    void registerwidget(ParentWidget *w);
    void event_loop();
};

#endif // PARENTWINDOW_HPP_INCLUDED
