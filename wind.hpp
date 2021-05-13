#ifndef WIND_HPP_INCLUDED
#define WIND_HPP_INCLUDED

#include "graphics.hpp"
#include "parentwidget.hpp"

class Wind:public ParentWidget{
protected:
    int _speed;
    int _direction;
    bool _change;
public:
    Wind(ParentWindow *parent, int x, int y, int x_size, int y_size);
    virtual void draw(int infocus, genv::event ev);
    virtual void action(genv::event ev);
    virtual void windchange();
    virtual int returnspeed();
    virtual int returndirection();
};

#endif // WIND_HPP_INCLUDED
