CC=gcc

# general build directory
BUILDDIR := build/
# animation directory
ANIMDIR := animations/
PYDIR := pylib/

TRIGFILES := lib/trig/trig.c
COORDFILES := lib/coord/coord.c
MATRIXFILES := lib/matrix/matrix.c

LIBTEST := tests/libtest/

trig: lib/trig/trig.h
	mkdir -p $(BUILDDIR)$@
	gcc -c $(TRIGFILES) -o $(BUILDDIR)$@/trig.o
	# building dynamic library for pylib
	# gcc -shared -o $(BUILDDIR)$@/triglib.so $(BUILDDIR)$@/trig.o 
	# building a static library for test cases
	ar -rc $(BUILDDIR)$@/libtrig.a $(BUILDDIR)$@/trig.o
	# copying the triglib to the respective building
	#mkdir -p $(PYDIR)$@/
	#cp $(BUILDDIR)$@/triglib.so $(PYDIR)$@/

coord: lib/coord/coord.h
	mkdir -p $(BUILDDIR)$@
	gcc -c $(COORDFILES) -o $(BUILDDIR)$@/coord.o
	# building dynamic library for pylib
	#gcc -shared -o $(BUILDDIR)$@/coordlib.so $(BUILDDIR)$@/coord.o
	# building a static library for test cases
	ar -rc $(BUILDDIR)$@/libcoord.a $(BUILDDIR)$@/coord.o $(BUILDDIR)trig/trig.o
	# copying the coordlib to the respective building
	mkdir -p $(PYDIR)$@/
	cp $(BUILDDIR)$@/coordlib.so $(PYDIR)$@/

matrix: lib/matrix/matrix.h
	mkdir -p $(BUILDDIR)$@
	gcc -c lib/matrix/matrix.h -o $(BUILDDIR)$@/mat.o
	ar -rc $(BUILDDIR)$@/libmat.a $(BUILDDIR)$@/mat.o
	mkdir -p $(PYDIR)$@/

trigtest: trig
	$(CC) $(LIBTEST)$@.c -lm -ltrig -o $(BUILDDIR)$^/$@ -I lib/$^ -L $(BUILDDIR)$^

coordtest: coord
	$(CC) $(LIBTEST)$@.c -lm -lcoord -o $(BUILDDIR)$^/$@ -I lib/$^ -L $(BUILDDIR)$^

#mattest: matrix
#	$(CC) $(LIBTEST)$@.c -lm -lmat -o $(BUILDDIR)$^/$@ -I lib/$^/$^.h -L $(BUILDDIR)$^
mattest: matrix
	cp -r lib/matrix/matrix.h $(LIBTEST)
	$(CC) $(LIBTEST)$@.c -o $(BUILDDIR)$^/$@

cleanbuild:
	rm -r build/*
