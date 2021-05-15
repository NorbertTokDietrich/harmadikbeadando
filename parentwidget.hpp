#ifndef PARENTWIDGET_HPP_INCLUDED
#define PARENTWIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include "parentwindow.hpp"

class ParentWidget{
protected:
    ParentWindow *_parent;
    int _x, _y, _x_size, _y_size, _clicked, _infocus;
public:
    ParentWidget(ParentWindow *parent, int x, int y, int x_size, int y_size);
    virtual bool is_clicked(int x_mouse, int y_mouse);
    virtual void draw(int infocus, genv::event ev)=0;
    virtual void action(genv::event ev)=0;
    virtual int returnx()=0;
    virtual int returny()=0;
    virtual int returnlx()=0;
    virtual int returnly()=0;
    virtual int returnrx()=0;
    virtual int returnry()=0;
};

#endif // PARENTWIDGET_HPP_INCLUDED
