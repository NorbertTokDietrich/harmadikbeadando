#include "numberset.hpp"
#include "graphics.hpp"

using namespace genv;

NumberSet::NumberSet(ParentWindow *parent, int x, int y, int x_size, int y_size, int startnumber, int lower, int upper, std::function <void()>fvmuts):
    ParentWidget(parent, x, y, x_size, y_size), _startnumber(startnumber), _lower(lower), _upper(upper), _fvmuts(fvmuts)
{
    _up=false;
    _down=false;
}

void NumberSet::draw(int infocus, event ev)
{
    int dimension=(_y_size-4)/2;
    gout<<move_to(_x,_y)<<color(255-infocus*185,255-infocus*47,255-infocus*56)<<box(_x_size,_y_size);
    gout<<move_to(_x+2,_y+2)<<color(0,0,0)<<box(_x_size-4,_y_size-4);
    gout<<move_to(_x+_x_size-2-dimension,_y+2)<<color(255-infocus*185,255-infocus*47,255-infocus*56)<<box(dimension,dimension);
    gout<<move_to(_x+_x_size-2-dimension,_y+2+dimension)<<color(255-infocus*185,255-infocus*47,255-infocus*56)<<box(dimension,dimension);
    gout<<move_to(_x+_x_size-2-dimension+2,_y+2)<<color(119,119,119)<<box(dimension-2,dimension-1);
    gout<<move_to(_x+_x_size-2-dimension+2,_y+3+dimension)<<color(119,119,119)<<box(dimension-2,dimension-1);
    gout << font("LiberationSans-Regular.ttf",20);
    gout<<move_to(_x+10,_y+8)<<color(255,255,255)<<text(std::to_string(_startnumber));
    gout << font("LiberationSans-Regular.ttf",20);
    int up;
    if(_up)
    {
        up=1;
    }
    else
    {
        up=0;
    }
    _up=false;
    int down;
    if(_down)
    {
        down=1;
    }
    else
    {
        down=0;
    }
    _down=false;
    gout<<move_to(_x+_x_size-2-dimension+5,_y+2+dimension-5)<<color(255-up*255,255-up*255,255-up*255)<<line_to(_x+_x_size-2-dimension/2,_y+2+5)<<move_to(_x+_x_size-2-dimension/2,_y+2+5)<<line_to(_x+_x_size-2-5,_y+2+dimension-5);
    gout<<move_to(_x+_x_size-2-dimension+5,_y+2+dimension+5)<<color(255-down*255,255-down*255,255-down*255)<<line_to(_x+_x_size-2-dimension/2,_y+2+2*dimension-5)<<move_to(_x+_x_size-2-dimension/2,_y+2+2*dimension-5)<<line_to(_x+_x_size-2-5,_y+2+dimension+5);
}

void NumberSet::action(event ev)
{
    if(ev.type==ev_mouse && ((ev.pos_x>_x+_x_size-2-(_y_size-4)/2) && (ev.pos_x<_x+_x_size-2) && (ev.pos_y>_y+2) && (ev.pos_y<_y+2+(_y_size-4)/2)) && (ev.button==btn_left))
    {
        _up=true;
        _startnumber++;
    }
    if(ev.type==ev_mouse && ((ev.pos_x>_x+_x_size-2-(_y_size-4)/2) && (ev.pos_x<_x+_x_size-2) && (ev.pos_y>_y+2+(_y_size-4)/2) && (ev.pos_y<_y+_y_size-2)) && ev.button==btn_left)
    {
        _down=true;
        _startnumber--;
    }
    if(ev.type==ev_key && ev.keycode==key_up)
    {
        _startnumber=_startnumber+10;
    }
    if(ev.type==ev_key && ev.keycode==key_down)
    {
        _startnumber=_startnumber-10;
    }
    if(_startnumber>_upper)
    {
        _startnumber=_upper;
    }
    if(_startnumber<_lower)
    {
        _startnumber=_lower;
    }
    _fvmuts();
}

int NumberSet::number()
{
    return _startnumber;
}

int NumberSet::returnx()
{
    return _x;
}

int NumberSet::returny()
{
    return _y;
}

int NumberSet::returnlx()
{
    return _x;
}

int NumberSet::returnly()
{
    return _y;
}

int NumberSet::returnrx()
{
    return _x;
}

int NumberSet::returnry()
{
    return _y;
}
