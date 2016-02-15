GPP   = g++ -std=c++14
FLAGS = -Wall -g -pthread

CC    = $(GPP) $(FLAGS)

all: ex

ex: install ex.cpp
	$(CC) ex.cpp -L. -lfit -o ex

install: libfit.so
	sudo cp libfit.so /usr/lib/

libfit.so: build
	$(CC) -shared -fPIC obj/*.o -o libfit.so


build: obj/ obj/app.o obj/fmatrix.o




obj/app.o: 	       src/core/app.cpp src/core/app.hpp obj/ui.o obj/fevent.o obj/finputhandler.o
	$(CC) -c -fPIC src/core/app.cpp -o obj/app.o
	
obj/ui.o: 	       src/ui/ui.cpp src/ui/ui.hpp obj/flabel.o obj/fthreadable.o
	$(CC) -c -fPIC src/ui/ui.cpp -o obj/ui.o

obj/flabel.o: 	   src/ui/flabel.cpp src/ui/flabel.hpp obj/fwidget.o obj/ftextalign.o 
	$(CC) -c -fPIC src/ui/flabel.cpp -o obj/flabel.o
	
obj/fwidget.o: 	   src/ui/fwidget.cpp src/ui/fwidget.hpp obj/fvector.o obj/frect.o obj/fpattern.o
	$(CC) -c -fPIC src/ui/fwidget.cpp -o obj/fwidget.o

obj/frect.o: 	   src/core/frect.cpp src/core/frect.hpp obj/fvec2.o
	$(CC) -c -fPIC src/core/frect.cpp -o obj/frect.o

obj/fvec2.o: 	   src/core/fvec2.cpp src/core/fvec2.hpp obj/fobject.o
	$(CC) -c -fPIC src/core/fvec2.cpp -o obj/fvec2.o

obj/fvector.o: 	   src/core/fvector.cpp src/core/fvector.hpp obj/fobject.o
	$(CC) -c -fPIC src/core/fvector.cpp -o obj/fvector.o

obj/fpattern.o: 	   src/ui/fpattern.cpp src/ui/fpattern.hpp obj/fobject.o
	$(CC) -c -fPIC src/ui/fpattern.cpp -o obj/fpattern.o

obj/finputhandler.o: src/ui/finputhandler.cpp src/ui/finputhandler.hpp obj/fevent.o obj/fthreadable.o
	$(CC) -c -fPIC src/ui/finputhandler.cpp -o obj/finputhandler.o

obj/fmatrix.o:     src/core/fmatrix.cpp src/core/fmatrix.hpp src/core/fmatrix_impl.cpp obj/fobject.o
	$(CC) -c -fPIC src/core/fmatrix.cpp -o obj/fmatrix.o

obj/fthreadable.o: src/core/fthreadable.cpp src/core/fthreadable.hpp obj/fobject.o
	$(CC) -c -fPIC src/core/fthreadable.cpp -o obj/fthreadable.o

obj/fevent.o: 	   src/core/fevent.cpp src/core/fevent.hpp obj/fobject.o
	$(CC) -c -fPIC src/core/fevent.cpp -o obj/fevent.o

obj/ftextalign.o:  src/ui/ftextalign.cpp src/ui/ftextalign.hpp obj/fobject.o
	$(CC) -c -fPIC src/ui/ftextalign.cpp -o obj/ftextalign.o

obj/ftools.o:  src/ui/ftools.cpp src/ui/ftools.hpp obj/fobject.o
	$(CC) -c -fPIC src/ui/ftools.cpp -o obj/ftools.o

obj/fobject.o: 	   src/core/fobject.cpp src/core/fobject.hpp
	$(CC) -c -fPIC src/core/fobject.cpp -o obj/fobject.o


obj/:
	mkdir obj

clean:
	sudo rm -rf obj/ libfit.so /usr/lib/libfit.so ex

notworking:
	export LD_LIBRARY_PATH=/home/antoine/prog/libfit/
