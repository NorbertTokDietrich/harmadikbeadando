#include "tank.hpp"
#include "graphics.hpp"
#include <cmath>
#include <math.h>

using namespace genv;
using namespace std;

Tank::Tank(ParentWindow *parent, int x, int y, int x_size, int y_size, int angle, int side):
    ParentWidget(parent, x, y, x_size, y_size), _angle(angle), _side(side)
{
    _angle=15;
    _shooting1=false;
    _shooting2=false;
    _t=0;
    double pi = 3.14159265359;
    _radian=(_angle * (pi / 180));
    _heightleftd=500;
    _heightrightd=400;
    if(_side==1)
    {
        _lx=_x+120;
        _ly=_y-50*sin(_radian);
    }
    if(_side==2)
    {
        _rx=_x-20;
        _ry=_y-50*sin(_radian);
    }
}

void Tank::draw(int infocus, event ev)
{
    double pi = 3.14159265359;
    _radian=(_angle * (pi / 180));
    gout<<move_to(_x, _y)<<color(43,159,39)<<box(100,40);
    gout<<move_to(_x+10, _y+40)<<color(50,50,50)<<box(80,10);
    gout<<move_to(_x+25, _y-15)<<color(43,159,39)<<box(50,15);

    if(_side==1)
    {
        for(int i=0; i<6; i++)
        {
            gout<<move_to(_x+75,_y-5-i)<<color(43,159,39)<<line_to(_x+120,_heightleftd-50-65*sin(_radian)-i);
        }
    }
    if(_side==2)
    {
        for(int i=0; i<6; i++)
        {
            gout<<move_to(_x+25,_y-5-i)<<color(43,159,39)<<line_to(_x-20,_heightrightd-50-65*sin(_radian)-i);
        }
    }

    if(_shooting1)
    {
        gout<<move_to(_lx, _ly)<<color(255,255,255)<<box(5,5);
    }

    if(_shooting2)
    {
        gout<<move_to(_rx, _ry)<<color(255,255,255)<<box(5,5);
    }

    //gout<<move_to(50,250)<<color(255,255,255)<<text(to_string(_shooting1));
    //gout<<move_to(50,300)<<color(255,255,255)<<text(to_string(_shooting2));
    //gout<<move_to(300,250)<<color(255,255,255)<<text(to_string(_x));
    //gout<<move_to(300,300)<<color(255,255,255)<<text(to_string(_y));
    //gout<<move_to(120,250)<<color(255,255,255)<<text(to_string(_lx));
    //gout<<move_to(120,300)<<color(255,255,255)<<text(to_string(_ly));
    //gout<<move_to(190,320)<<color(255,255,255)<<text(to_string(_rx));
    //gout<<move_to(190,350)<<color(255,255,255)<<text(to_string(_ry));
}

void Tank::action(event ev)
{
    if(_shooting1)
    {
        _lx=_lx+_initialspeed*cos(_radian)/2+_windspeed/5+_winddirection/2;
        _ly=_ly-_initialspeed*sin(_radian)+9.81*_t;
        _t=_t+0.001;
        if(_ly>_heightrightd-10 && _lx>450 && _lx<790)
        {
            _shooting1=false;
            _t=0;
            _lx=_x+120;
            _ly=_y-50*sin(_radian);
        }
        if(_lx>790 || _ly<10)
        {
            _shooting1=false;
            _t=0;
            _lx=_x+120;
            _ly=_y-50*sin(_radian);
        }
        if(_ly>_heightleftd-10 && _lx>10 && _lx<450)
        {
            _shooting1=false;
            _t=0;
            _lx=_x+120;
            _ly=_y-50*sin(_radian);
        }
    }
    if(_shooting2)
    {
        _rx=_rx-_initialspeed*cos(_radian)/2-_windspeed/5-_winddirection/2;
        _ry=_ry-_initialspeed*sin(_radian)+9.81*_t;
        _t=_t+0.001;
        if(_ry>_heightleftd-10 && _rx<350 && _rx>10)
        {
            _shooting2=false;
            _t=0;
            _rx=_x-20;
            _ry=_y-50*sin(_radian);
        }
        if(_rx<10 || _ry<10)
        {
            _shooting2=false;
            _t=0;
            _rx=_x-20;
            _ry=_y-50*sin(_radian);
        }
        if(_ry>_heightrightd-10 && _rx>450 && _rx<790)
        {
            _shooting2=false;
            _t=0;
            _rx=_x-20;
            _ry=_y-50*sin(_radian);
        }
    }
}

bool Tank::firsttankok(int a, int b)
{
    if(_rx>=a && _rx<=(a+100) && _ry>=b-15)
    {
        return false;
    }
    return true;
}

bool Tank::secondtankok(int a, int b)
{
    if(_lx>=a && _lx<=(a+100) && _ly>=b-15)
    {
        return false;
    }
    return true;
}

void Tank::goleft()
{
    if(_side==1)
    {
        if(_x>=22 && _x<=248)
        {
            _x=_x-2;
        }
        else
        {
            if(_x<=22)
            {
                _x=_x+5;
            }
        }
    }
    if(_side==2)
    {
        if(_x>=452 && _x<=678)
        {
            _x=_x-2;
        }
        else
        {
            if(_x<=452)
            {
                _x=_x+5;
            }
        }
    }
}

void Tank::goright()
{
    if(_side==1)
    {
        if(_x>=22 && _x<=248)
        {
            _x=_x+2;
        }
        else
        {
            if(_x>=248)
            {
                _x=_x-5;
            }
        }
    }
    if(_side==2)
    {
        if(_x>=452 && _x<=678)
        {
            _x=_x+2;
        }
        else
        {
            if(_x>=678)
            {
                _x=_x-5;
            }
        }
    }
}

void Tank::shoot1()
{
    _shooting1=true;
    _t=0;
}

void Tank::shoot2()
{
    _shooting2=true;
    _t=0;
}

void Tank::setangle(int n)
{
    _angle=n;
}

void Tank::setinitialspeed(int n)
{
    _initialspeed=n;
}

void Tank::setwindspeed(int n)
{
    _windspeed=n;
}

void Tank::setwinddirection(int n)
{
    _winddirection=n;
}

int Tank::returnx()
{
    return _x;
}

int Tank::returny()
{
    return _y;
}

int Tank::returnlx()
{
    return _lx;
}

int Tank::returnly()
{
    return _ly;
}

int Tank::returnrx()
{
    return _rx;
}

int Tank::returnry()
{
    return _ry;
}

int Tank::returnshoot1()
{
    return _shooting1;
}

int Tank::returnshoot2()
{
    return _shooting2;
}

void Tank::setshoot1()
{
    _shooting1=true;
    _shooting2=false;
}

void Tank::setshoot2()
{
    _shooting1=false;
    _shooting2=true;
}

void Tank::refreshpositionleft()
{
    _lx=_x+120;
    _ly=_y-50*sin(_radian);
}

void Tank::refreshpositionright()
{
    _rx=_x-20;
    _ry=_y-50*sin(_radian);
}
