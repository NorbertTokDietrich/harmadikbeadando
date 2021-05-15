#include "optionset.hpp"
#include "graphics.hpp"
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace genv;

OptionSet::OptionSet(ParentWindow *parent, int x, int y, int x_size, int y_size, std::string inputsentence, int xans, int yans, int windowheight):
    ParentWidget(parent,x,y,x_size,y_size), _inputsentence(inputsentence), _xans(xans), _yans(yans), _windowheight(windowheight)
{
    _isinfocus=0;
    _clicked=false;
    _ans=-1;
    _numberofoptions=0;
    _starter=0;
    _temp=0;
    _seged2=(_windowheight-_y)/_y_size;
    std::string szo="";
    for(int i=0; i<_inputsentence.size(); i++)
    {
        if(_inputsentence[i]=='/')
        {
            lista.push_back(szo);
            szo="";
        }
        else
        {
            szo=szo+_inputsentence[i];
        }
    }
    _numberofoptions=lista.size();
}

void OptionSet::draw(int infocus, event ev)
{
    gout << font("LiberationSans-Regular.ttf",15);
    double ansd=-1;
    if(ev.type==ev_mouse && ((ev.pos_x>=_x) && (ev.pos_x<=(_x+_x_size)) && (ev.pos_y>=_y) && (ev.pos_y<=(_y+_seged2*_y_size)) && (ev.button==btn_left)))
    {
        ansd=(ev.pos_y-_y)/_y_size;
        _ans=floor(ansd);
    }
    if(ev.type==ev_mouse && (ev.pos_x>=_x && ev.pos_x<=(_x+_x_size) && ev.pos_y>=_y && ev.pos_y<=(_y+_seged2*_y_size)))
    {
        _isinfocus=1;
    }
    else
    {
        _isinfocus=0;
    }
    if((_y+_numberofoptions*_y_size)<_windowheight)
    {
        for(int i=0; i<_numberofoptions; i++)
        {
            if(_ans!=-1 && i==_ans)
            {
                gout<<move_to(_x,_y+i*_y_size)<<color(255-_isinfocus*185,255-_isinfocus*47,255-_isinfocus*56)<<box(_x_size,_y_size);
                gout<<move_to(_x+2,_y+i*_y_size+2)<<color(119,119,119)<<box(_x_size-4,_y_size-4);
                gout<<move_to(_x+15,_y+i*_y_size+5)<<color(255,255,255)<<text(lista[i]);
            }
            else
            {
                gout<<move_to(_x,_y+i*_y_size)<<color(255-_isinfocus*185,255-_isinfocus*47,255-_isinfocus*56)<<box(_x_size,_y_size);
                gout<<move_to(_x+2,_y+i*_y_size+2)<<color(0,0,0)<<box(_x_size-4,_y_size-4);
                gout<<move_to(_x+15,_y+i*_y_size+5)<<color(255,255,255)<<text(lista[i]);
            }
        }
    }
    else
    {
        int up=0;
        int down=0;
        for(int i=_starter, j=0; i<_starter+_seged2 && j<_seged2; i++, j++)
        {
            if(_ans!=-1 && j==_ans)
            {
                gout<<move_to(_x,_y+j*_y_size)<<color(255-_isinfocus*185,255-_isinfocus*47,255-_isinfocus*56)<<box(_x_size,_y_size);
                gout<<move_to(_x+2,_y+j*_y_size+2)<<color(119,119,119)<<box(_x_size-4,_y_size-4);
                gout<<move_to(_x+15,_y+j*_y_size+5)<<color(255,255,255)<<text(lista[i]);
            }
            else
            {
                gout<<move_to(_x,_y+j*_y_size)<<color(255-_isinfocus*185,255-_isinfocus*47,255-_isinfocus*56)<<box(_x_size,_y_size);
                gout<<move_to(_x+2,_y+j*_y_size+2)<<color(0,0,0)<<box(_x_size-4,_y_size-4);
                gout<<move_to(_x+15,_y+j*_y_size+5)<<color(255,255,255)<<text(lista[i]);
            }
            up=i;
            down=j;
        }
        _temp=up-down;
    }
    gout<<move_to(_xans,_yans)<<color(255,255,255)<<box(_x_size,_y_size);
    gout<<move_to(_xans+2,_yans+2)<<color(0,0,0)<<box(_x_size-4,_y_size-4);
    if(_ans!=-1)
    {
        gout<<move_to(_xans+15,_yans+5)<<color(255,255,255)<<text(lista[_ans+_temp]);
    }
}

void OptionSet::action(event ev)
{
    double ansd=-1;
    if(ev.type==ev_mouse && ((ev.pos_x>=_x) && (ev.pos_x<=(_x+_x_size)) && (ev.pos_y>=_y) && (ev.pos_y<=(_y+_seged2*_y_size)) && ev.button==btn_wheeldown))
    {
        _starter++;
    }
    if(ev.type==ev_mouse && ((ev.pos_x>=_x) && (ev.pos_x<=(_x+_x_size)) && (ev.pos_y>=_y) && (ev.pos_y<=(_y+_seged2*_y_size)) && ev.button==btn_wheelup))
    {
        _starter--;
    }
    if(_starter<0)
    {
        _starter=0;
    }
    if(_starter>_numberofoptions-_seged2)
    {
        _starter=_numberofoptions-_seged2;
    }
    if(ev.type==ev_mouse && ((ev.pos_x>=_x) && (ev.pos_x<=(_x+_x_size)) && (ev.pos_y>=_y) && (ev.pos_y<=(_y+_numberofoptions*_y_size)) && (ev.button==btn_left)))
    {
        ansd=(ev.pos_y-_y)/_y_size;
        _ans=floor(ansd);
    }
}

std::string OptionSet::answearstring()
{
    std::string default_str="-";
    if(_ans==-1)
    {
        return default_str;
    }
    return lista[_ans+_temp];
}

int OptionSet::returnx()
{
    return _x;
}

int OptionSet::returny()
{
    return _y;
}

int OptionSet::returnlx()
{
    return _x;
}

int OptionSet::returnly()
{
    return _y;
}

int OptionSet::returnrx()
{
    return _x;
}

int OptionSet::returnry()
{
    return _y;
}
