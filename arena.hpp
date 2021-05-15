#ifndef ARENA_HPP_INCLUDED
#define ARENA_HPP_INCLUDED

#include "graphics.hpp"
#include "parentwidget.hpp"

class Arena:public ParentWidget{
protected:
    int _height1;
    int _height2;
public:
    Arena(ParentWindow *parent, int x, int y, int x_size, int y_size, int height1, int height2);
    virtual void draw(int infocus, genv::event ev);
    virtual void action(genv::event ev);
    virtual int returnx();
    virtual int returny();
    virtual int returnlx();
    virtual int returnly();
    virtual int returnrx();
    virtual int returnry();
};

#endif // ARENA_HPP_INCLUDED
