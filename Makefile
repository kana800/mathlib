CC=gcc

BUILDDIR := build/

TRIGFILES := lib/trig.c
LIBTEST := tests/libtest/

trig: lib/trig.h
	mkdir -p $(BUILDDIR)
	ls -al $(TRIGFILES)
	gcc -c $(TRIGFILES)  -o $(BUILDDIR)trig.o
	ls -al $(BUILDDIR)
	ar -rcs $(BUILDDIR)trig.a $(BUILDDIR)trig.o
trigtest: trig
	gcc $(LIBTEST)trigtest.c -o trigtest -static -L. $(BUILDDIR)trig.a -lm
