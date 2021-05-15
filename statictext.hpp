#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "graphics.hpp"
#include "parentwidget.hpp"

class StaticText : public ParentWidget{
protected:
    std::string _cimke;
public:
    StaticText(ParentWindow *parent, int x, int y, int x_size, int y_size, std::string _cimke);
    virtual void draw(int infocus, genv::event ev);
    virtual void action(genv::event ev);
    virtual void settext(std::string c);
    virtual void deletestr();
    virtual int returnx();
    virtual int returny();
    virtual int returnlx();
    virtual int returnly();
    virtual int returnrx();
    virtual int returnry();
};

#endif // STATICTEXT_HPP_INCLUDED
