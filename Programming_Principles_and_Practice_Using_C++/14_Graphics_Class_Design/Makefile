CC      =  $(shell fltk-config --cxx)
CXXFLAGS = $(shell fltk-config --use-gl --use-images --cxxflags )
LDINCLUDES = -L/usr/local/Cellar/fltk/1.3.5/lib -lfltk_images -L/usr/local/Cellar/libpng/1.6.37/lib -lpng16 -lz -L/usr/local/Cellar/jpeg/9d/lib -ljpeg -lfltk_gl -framework OpenGL -lfltk -lpthread -framework Cocoa
LDFLAGS  = $(shell fltk-config --use-gl --use-images --ldflags )
LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags )

all: main

clean:
	rm -f *.o

# ==== FLTK LIBRARY ====
Graph.o: Graph.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

GUI.o: GUI.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

Window.o: Window.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

# ==== MAIN FILE ====
main: Graph.o GUI.o Window.o
	$(CC) $(CXXFLAGS) -o app Main.cpp Graph.o GUI.o Window.o $(LDINCLUDES)