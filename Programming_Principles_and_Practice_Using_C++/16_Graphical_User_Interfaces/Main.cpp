#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title);
    Open_polyline lines;

private:
    Button next_button;
    Button quit_button;
    Menu color_menu;
    Button menu_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;

    void next();
    void quit() { hide(); }

    void red_pressed() { change_color(Color::red); }
    void green_pressed() { change_color(Color::green); }
    void blue_pressed() { change_color(Color::blue); }
    void change_color(Color color);

    void menu_button_clicked();
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    : Graph_lib::Window(xy, w, h, title),
      next_button{Point{x_max() - 150, 0}, 70, 20, "Next",
                  [](Address, Address addr) { static_cast<Lines_window*>(addr)->next(); }},
      quit_button{Point{x_max() - 70, 0}, 70, 20, "Quit",
                  [](Address, Address addr) { static_cast<Lines_window*>(addr)->quit(); }},
      color_menu{Point{x_max() - 70, 40}, 70, 20, Menu::vertical, "colors"},
      menu_button{Point{x_max() - 70, 40}, 70, 20, "color menu",
                  [](Address, Address addr) { static_cast<Lines_window*>(addr)->menu_button_clicked(); }},
      next_x{Point{x_max() - 310, 0}, 50, 20, "next x:"},
      next_y{Point{x_max() - 210, 0}, 50, 20, "next y:"},
      xy_out{Point{100, 0}, 100, 20, "current (x,y):"}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);

    color_menu.attach(new Button{Point{0, 0}, 0, 0, "red",
                                 [](Address, Address addr) { static_cast<Lines_window*>(addr)->red_pressed(); }});
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "green",
                                 [](Address, Address addr) { static_cast<Lines_window*>(addr)->green_pressed(); }});
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "blue",
                                 [](Address, Address addr) { static_cast<Lines_window*>(addr)->blue_pressed(); }});
    attach(color_menu);
    color_menu.hide();

    attach(menu_button);
}

void Lines_window::change_color(Color c)
{
    lines.set_color(c);
    color_menu.hide();
    menu_button.show();
    redraw();
}

void Lines_window::menu_button_clicked()
{
    menu_button.hide();
    color_menu.show();
    redraw();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add(Point{x, y});

    ostringstream oss;
    oss << '(' << x << ',' << y << ')';
    xy_out.put(oss.str());

    redraw();
}

int main()
{
    try {
        Lines_window win{Point{100, 100}, 600, 400, "lines"};
        return gui_main();
    } catch (exception& e) {
        cout << "Exception caught: " << e.what() << '\n';
        return 1;
    } catch (...) {
        cout << "Unhandled exception caught\n";
        return 2;
    }
}
