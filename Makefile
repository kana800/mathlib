CC=gcc

# general build directory
BUILDDIR := build/

TRIGFILES := lib/trig/trig.c
LIBTEST := tests/libtest/

trig: lib/trig/trig.h
	mkdir -p $(BUILDDIR)$@
	gcc -c -fPIC $(TRIGFILES) -o $(BUILDDIR)$@/trig.o
	gcc -shared -o $(BUILDDIR)$@/trig.so $(BUILDDIR)$@/trig.o 
	ar -rcs $(BUILDDIR)$@/trig.a $(BUILDDIR)$@/trig.o

trigtest: trig
	gcc $(LIBTEST)trigtest.c -o $(BUILDDIR)$^/trigtest -static -L. $(BUILDDIR)$^/trig.a -lm

cleantest: 
	rm -r trigtest
