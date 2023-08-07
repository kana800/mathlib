CC=gcc

# general build directory
BUILDDIR := build/
# animation directory
ANIMDIR := animations/

TRIGFILES := lib/trig/trig.c
COORDFILES := lib/coord/coord.c
MATRIXFILES := lib/matrix/matrix.c

LIBTEST := tests/libtest/
MODULETEST := tests/moduletest/

matrix: lib/matrix/matrix.h
	mkdir -p $(BUILDDIR)$@
	gcc -c lib/matrix/matrix.h -o $(BUILDDIR)$@/mat.o
	ar -rc $(BUILDDIR)$@/libmat.a $(BUILDDIR)$@/mat.o

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
	# cleaning the directories
	rm -r $(MODULETEST)linalg/*.h

cleanbuild:
	rm -r build/*
