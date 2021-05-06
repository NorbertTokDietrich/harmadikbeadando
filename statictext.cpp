#include "statictext.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;

StaticText::StaticText(ParentWindow *parent, int x, int y, int x_size, int y_size, string cimke): ParentWidget(parent, x, y, x_size, y_size), _cimke(cimke)
{

}

void StaticText::draw(int infocus, event ev)
{
    gout << font("LiberationSans-Regular.ttf",15);
    gout<<move_to(_x,_y)<<color(255,255,255)<<text(_cimke);
}

void StaticText::action(event ev)
{

}

void StaticText::settext(string c)
{
    _cimke=_cimke+c;
}

void StaticText::deletestr()
{
    _cimke="";
}
