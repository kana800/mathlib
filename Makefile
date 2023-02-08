CC=gcc

# general build directory
BUILDDIR := build/
# animation directory
ANIMDIR := animations/
PYDIR := pylib/

TRIGFILES := lib/trig/trig.c
LIBTEST := tests/libtest/

trig: lib/trig/trig.h
	mkdir -p $(BUILDDIR)$@
	gcc -c -fPIC $(TRIGFILES) -o $(BUILDDIR)$@/trig.o
	# building dynamic library for pylib
	gcc -shared -o $(BUILDDIR)$@/triglib.so $(BUILDDIR)$@/trig.o 
	# building a static library for test cases
	ar -rcs $(BUILDDIR)$@/trig.a $(BUILDDIR)$@/trig.o
	# copying the triglib to the respective building
	cp $(BUILDDIR)$@/triglib.so $(PYDIR)$@/

trigtest: trig
	gcc $(LIBTEST)trigtest.c -o $(BUILDDIR)$^/trigtest -static -L. $(BUILDDIR)$^/trig.a -lm

cleantest: 
	rm -r trigtest
