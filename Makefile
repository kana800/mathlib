CC=gcc

# general build directory
BUILDDIR := build/
# animation directory
ANIMDIR := animations/
PYDIR := pylib/

TRIGFILES := lib/trig/trig.c
COORDFILES := lib/coord/coord.c
LIBTEST := tests/libtest/

trig: lib/trig/trig.h
	mkdir -p $(BUILDDIR)$@
	gcc -c -fPIC $(TRIGFILES) -o $(BUILDDIR)$@/trig.o
	# building dynamic library for pylib
	gcc -shared -o $(BUILDDIR)$@/triglib.so $(BUILDDIR)$@/trig.o 
	# building a static library for test cases
	ar -rcs $(BUILDDIR)$@/trig.a $(BUILDDIR)$@/trig.o
	# copying the triglib to the respective building
	mkdir -p $(PYDIR)$@/
	cp $(BUILDDIR)$@/triglib.so $(PYDIR)$@/

coord: lib/coord/coord.h
	mkdir -p $(BUILDDIR)$@
	gcc -c -fPIC $(COORDFILES) -o $(BUILDDIR)$@/coord.o
	# building dynamic library for pylib
	gcc -shared -o $(BUILDDIR)$@/coordlib.so $(BUILDDIR)$@/coord.o
	# building a static library for test cases
	ar -rcs $(BUILDDIR)$@/coord.a $(BUILDDIR)$@/coord.o $(BUILDDIR)trig/trig.o
	# copying the coordlib to the respective building
	mkdir -p $(PYDIR)$@/
	cp $(BUILDDIR)$@/coordlib.so $(PYDIR)$@/

trigtest: trig
	gcc $(LIBTEST)trigtest.c -o $(BUILDDIR)$^/trigtest -static -L. $(BUILDDIR)$^/trig.a -lm

coordtest: coord
	gcc $(LIBTEST)coordtest.c -o $(BUILDDIR)$^/coordtest -static -L. $(BUILDDIR)$^/coord.a

cleantest: 
	rm -r trigtest
	rm -r coordtest

cleanbuild:
	rm -r build/*
