#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
try
{
    Point tl{100, 100};

    Simple_window win{tl, 600, 400, "Canvas"};

    Image ii{Point{50, 100}, "image.jpg"};
    win.attach(ii);

    Axis xa{Axis::x, Point{20, 300}, 280, 10, "x axis"};
    win.attach(xa);

    Axis ya{Axis::y, Point{20, 300}, 280, 10, "y axis"};
    ya.set_color(Color::dark_blue);
    ya.label.set_color(Color::dark_magenta);
    win.attach(ya);

    Function sine{sin, 0, 100, Point{20, 150}, 1000, 50, 50};
    sine.set_color(Color::cyan);
    win.attach(sine);

    Polygon poly;
    poly.add(Point{300, 200});
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);

    Rectangle r{Point{100, 200}, 100, 50};
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{150, 50});
    poly_rect.add(Point{150, 100});
    poly_rect.add(Point{100, 100});
    poly_rect.add(Point{50, 75});
    win.attach(poly_rect);

    r.set_fill_color(Color::dark_yellow);
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dot, 2));
    poly_rect.set_fill_color(Color::dark_green);

    Text t{Point{150, 150}, "Hello, graphic world!"};
    win.attach(t);

    win.wait_for_button();
}
catch (exception &e)
{
    return 1;
}
catch (...)
{
    return 2;
}