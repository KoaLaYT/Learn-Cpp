#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
try
{
    Point tl{100, 100};

    Simple_window win{tl, 600, 400, "Canvas"};

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