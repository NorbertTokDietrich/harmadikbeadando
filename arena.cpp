#include "arena.hpp"
#include "graphics.hpp"
#include "parentwindow.hpp"

using namespace genv;
using namespace std;

Arena::Arena(ParentWindow *parent, int x, int y, int x_size, int y_size, int height1, int height2):
    ParentWidget(parent, x, y, x_size, y_size), _height1(height1), _height2(height2)
{

}

void Arena::draw(int infocus, event ev)
{
    gout<<move_to(0,_height1)<<color(255,255,255)<<box(350,4);
    gout<<move_to(350,_height1)<<color(255,255,255)<<line_to(450,_height2);
    gout<<move_to(450,_height2)<<color(255,255,255)<<box(350,4);
}

void Arena::action(event ev)
{

}
