#ifndef TANK_HPP_INCLUDED
#define TANK_HPP_INCLUDED

#include "graphics.hpp"
#include "parentwidget.hpp"

class Tank:public ParentWidget{
protected:
    int _side;
    int _angle;
    double _lx;
    double _ly;
    double _rx;
    double _ry;
    bool _shooting;
    double _t;
    double _radian;
    bool _shooting1;
    bool _shooting2;
    int _heightleftd;
    int _heightrightd;
    int _initialspeed;
    int _windspeed;
    int _winddirection;
public:
    Tank(ParentWindow *parent, int x, int y, int x_size, int y_size, int angle, int side);
    virtual void draw(int infocus, genv::event ev);
    virtual void action(genv::event ev);
    virtual void goleft();
    virtual void goright();
    virtual void shoot1();
    virtual void shoot2();
    virtual void setangle(int n);
    virtual void setinitialspeed(int n);
    virtual void setwinddirection(int n);
    virtual void setwindspeed(int n);
    virtual int returnx();
    virtual int returny();
    virtual int returnshoot1();
    virtual int returnshoot2();
};

#endif // TANK_HPP_INCLUDED
