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
MODULETEST := tests/moduletest/

trig: lib/trig/trig.h
	mkdir -p $(BUILDDIR)$@
	gcc -c $(TRIGFILES) -o $(BUILDDIR)$@/trig.o
	ar -rc $(BUILDDIR)$@/libtrig.a $(BUILDDIR)$@/trig.o
	# copying the triglib to the respective building
	#mkdir -p $(PYDIR)$@/
	#cp $(BUILDDIR)$@/triglib.so $(PYDIR)$@/

coord: lib/coord/coord.h
	mkdir -p $(BUILDDIR)$@
	gcc -c $(COORDFILES) -o $(BUILDDIR)$@/coord.o
	ar -rc $(BUILDDIR)$@/libcoord.a $(BUILDDIR)$@/coord.o $(BUILDDIR)trig/trig.o
	mkdir -p $(PYDIR)$@/
	cp $(BUILDDIR)$@/coordlib.so $(PYDIR)$@/

trigtest: trig
	$(CC) $(LIBTEST)$@.c -lm -ltrig -o $(BUILDDIR)$^/$@ -I lib/$^ -L $(BUILDDIR)$^

coordtest: coord
	$(CC) $(LIBTEST)$@.c -lm -lcoord -o $(BUILDDIR)$^/$@ -I lib/$^ -L $(BUILDDIR)$^

matrix: lib/matrix/matrix.h
	mkdir -p $(BUILDDIR)$@
	gcc -c lib/matrix/matrix.h -o $(BUILDDIR)$@/mat.o
	ar -rc $(BUILDDIR)$@/libmat.a $(BUILDDIR)$@/mat.o
	mkdir -p $(PYDIR)$@/

mattest: matrix 
	cp -r lib/matrix/*.h $(LIBTEST)matrices/
	$(CC) $(LIBTEST)matrices/$@.c -o $(BUILDDIR)$^/$@
	# cleaning the directories
	rm -r $(LIBTEST)matrices/*.h

gausstest: matrix modules/linalg/gaussjordan.h
	cp -r lib/matrix/*.h $(MODULETEST)linalg/
	cp -r modules/linalg/gaussjordan.h $(MODULETEST)linalg/
	mkdir -p $(BUILDDIR)linalg/
	$(CC) $(MODULETEST)linalg/$@.c -o $(BUILDDIR)linalg/$@

cleanbuild:
	rm -r build/*
