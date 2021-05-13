#ifndef NUMBERSET_HPP_INCLUDED
#define NUMBERSET_HPP_INCLUDED

#include "graphics.hpp"
#include "parentwidget.hpp"
#include <functional>

typedef void(*FVMuts)();

class NumberSet:public ParentWidget{
protected:
    bool _up;
    bool _down;
    int _startnumber;
    int _lower;
    int _upper;
    std::function <void()>_fvmuts;
public:
    NumberSet(ParentWindow *parent, int x, int y, int x_size, int y_size, int startnumber, int lower, int upper, std::function <void()>fvmuts);
    virtual void draw(int infocus, genv::event ev);
    virtual void action(genv::event ev);
    virtual int number();
};

#endif // NUMBERSET_HPP_INCLUDED
