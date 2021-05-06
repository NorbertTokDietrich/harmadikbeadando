#include "button.hpp"
#include "graphics.hpp"

using namespace genv;

Button::Button(ParentWindow * parent, int x, int y, int x_size, int y_size, std::string textstr, std::function <void()>fvmut):ParentWidget(parent,x,y,x_size,y_size), _textstr(textstr), _fvmut(fvmut)
{
    _pressed=false;
}

void Button::draw(int infocus, event ev)
{
    gout<<move_to(_x,_y)<<color(255-infocus*185,255-infocus*47,255-infocus*56)<<box(_x_size,_y_size);
    gout<<move_to(_x+2,_y+2)<<color(0+_pressed*119,0+_pressed*119,0+_pressed*119)<<box(_x_size-4,_y_size-4);
    gout<<move_to(_x+14,_y+8)<<color(255,255,255)<<text(_textstr);
}

void Button::action(event ev)
{
    if(is_clicked(ev.pos_x,ev.pos_y) && ev.button==btn_left)
    {
        _pressed=true;
    }
    if(_pressed && is_clicked(ev.pos_x,ev.pos_y) && ev.button==-btn_left)
    {
        _fvmut();
    }
    if(ev.button==-btn_left || !is_clicked(ev.pos_x, ev.pos_y))
    {
        _pressed=false;
    }
}

bool Button::is_pressed()
{
    return _pressed;
}
