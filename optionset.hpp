#ifndef OPTIONSET_HPP_INCLUDED
#define OPTIONSET_HPP_INCLUDED

#include "graphics.hpp"
#include "parentwidget.hpp"

class OptionSet:public ParentWidget{
protected:
    int _isinfocus;
    bool _clicked;
    std::string _inputsentence;
    int _xans;
    int _yans;
    int _ans;
    std::vector<std::string> lista;
    int _numberofoptions;
    int _starter;
    int _windowheight;
    int _temp;
    int _seged2;
public:
    OptionSet(ParentWindow *parent, int x, int y, int x_size, int y_size, std::string inputsentence, int xans, int yans, int windowheight);
    virtual void draw(int infocus, genv::event ev);
    virtual void action(genv::event ev);
    virtual std::string answearstring();
    virtual int returnx();
    virtual int returny();
    virtual int returnlx();
    virtual int returnly();
    virtual int returnrx();
    virtual int returnry();
};

#endif // OPTIONSET_HPP_INCLUDED
