#ifndef PARENTWINDOW_HPP_INCLUDED
#define PARENTWINDOW_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>

class ParentWidget; //forward deklar�ci�: ez a t�pus l�tezni fog, de m�g nincs

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
