#include "parentwidget.hpp"
#include "graphics.hpp"

using namespace genv;

ParentWidget::ParentWidget(ParentWindow *parent, int x, int y, int x_size, int y_size):
    _parent(parent), _x(x), _y(y), _x_size(x_size), _y_size(y_size)
{
    _parent->registerwidget(this);
}

bool ParentWidget::is_clicked(int x_mouse, int y_mouse)
{
    return x_mouse>_x && x_mouse<_x+_x_size && y_mouse>_y && y_mouse<_y+_y_size;
}
