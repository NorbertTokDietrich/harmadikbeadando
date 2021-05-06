#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "parentwidget.hpp"
#include <functional>

typedef void(*FVMut)();

class Button:public ParentWidget{
protected:
    bool _pressed;
    std::string _textstr;
    std::function <void()>_fvmut;
public:
    Button(ParentWindow * parent, int x, int y, int x_size, int y_size, std::string textstr, std::function <void()>fvmut);
    virtual void draw(int infocus, genv::event ev);
    virtual void action(genv::event ev);
    virtual bool is_pressed();
};

#endif // BUTTON_HPP_INCLUDED
