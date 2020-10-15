#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

int main() {
    try {
        Point tl{100, 100};

        Simple_window win{tl, 600, 400, "Canvas"};

        int x_max = win.x_max();

        Lines grid;
        for (int x = 10; x < x_max; x += 10) {
            grid.add(Point{x, 50}, Point{x - 10, 60});
        }
        win.attach(grid);

        Open_polyline op{Point{50, 60}, Point{110, 150}, Point{90, 100}};
        win.attach(op);

        Closed_polyline cp{Point{150, 60}, Point{210, 150}, Point{170, 120}, Point{190, 100}};
        win.attach(cp);

        Polygon poly{Point{250, 60}, Point{270, 120}, Point{310, 150}, Point{290, 100}};
        win.attach(poly);

        Rectangle r1{Point{50, 150}, 50, 50};
        Rectangle r2{Point{100, 150}, 50, 50};
        Rectangle r3{Point{50, 200}, 50, 50};
        Rectangle r4{Point{100, 200}, 50, 50};
        r1.set_fill_color(Color::red);
        r1.set_color(Color::invisible);
        r2.set_fill_color(Color::green);
        r2.set_color(Color::invisible);
        r3.set_fill_color(Color::blue);
        r3.set_color(Color::invisible);
        r4.set_fill_color(Color::yellow);
        r4.set_color(Color::invisible);
        win.attach(r1);
        win.attach(r2);
        win.attach(r3);
        win.attach(r4);

        Marked_polyline mp{"XO"};
        mp.add(Point{50, 250});
        mp.add(Point{70, 270});
        mp.add(Point{90, 230});
        mp.add(Point{110, 200});
        win.attach(mp);

        win.wait_for_button();

        Vector_ref<Rectangle> vr;
        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 16; ++j) {
                vr.push_back(new Rectangle{Point{i * 20 + 250, j * 20 + 50}, 20, 20});
                vr[vr.size() - 1].set_fill_color(Color{i * 16 + j});
                win.attach(vr[vr.size() - 1]);
            }
        }

        win.wait_for_button();
    } catch (exception& e) {
        cout << "Exception caught: " << e.what() << '\n';
        return 1;
    } catch (...) {
        cout << "Unhandled exception caught\n";
        return 2;
    }
}
