#include "wind.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;

Wind::Wind(ParentWindow *parent, int x, int y, int x_size, int y_size):
    ParentWidget(parent, x, y, x_size, y_size)
{
    _speed=1+rand()%(5);
    _direction=-1+rand()%3;
    _change=false;
}

void Wind::draw(int infocus, event ev)
{
    gout<<move_to(_x,_y)<<color(255,255,255)<<box(_x_size,_y_size);
    gout<<move_to(_x+2,_y+2)<<color(0,0,0)<<box((_x_size-4)/2,_y_size-4);
    gout<<move_to(_x+2+(_x_size-4)/2+2,_y+2)<<color(0,0,0)<<box((_x_size-4)/2-2,_y_size-4);
    gout<<move_to(_x+5,_y+1)<<color(255,255,255)<<text("Direction");
    gout<<move_to(_x+_x_size-62,_y+1)<<color(255,255,255)<<text("Speed");
    if(_change)
    {
        _speed=1+rand()%(10);
        _direction=-1+rand()%3;
    }
    if(_direction==1)
    {
        gout<<move_to(_x+5,_y+30)<<color(255,255,255)<<text("East");
    }
    if(_direction==0)
    {
        gout<<move_to(_x+5,_y+30)<<color(255,255,255)<<text("Quiet");
    }
    if(_direction==-1)
    {
        gout<<move_to(_x+5,_y+30)<<color(255,255,255)<<text("West");
    }
    gout<<move_to(_x+_x_size-62,_y+30)<<color(255,255,255)<<text(to_string(_speed));
    _change=false;
}

void Wind::action(event ev)
{

}

void Wind::windchange()
{
    _change=true;
}

int Wind::returnspeed()
{
    return _speed;
}

int Wind::returndirection()
{
    return _direction;
}

int Wind::returnx()
{
    return _x;
}

int Wind::returny()
{
    return _y;
}

int Wind::returnlx()
{
    return _x;
}

int Wind::returnly()
{
    return _y;
}

int Wind::returnrx()
{
    return _x;
}

int Wind::returnry()
{
    return _y;
}
