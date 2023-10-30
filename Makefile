CC=gcc

# general build directory
BUILDDIR := build
# animation directory
ANIMDIR := animations
# test directory
TESTDIR := tests

TRIGFILES := lib/trig/trig.c
COORDFILES := lib/coord/coord.c
MATRIXFILES := lib/matrix/matrix.c

mattest:  
	# copying the header-only library
	cp -r lib/matrix/*.h $(TESTDIR)/matrices/
	$(CC) -mavx $(TESTDIR)/matrices/$@.c -o $(BUILDDIR)$^/$@
	# cleaning the directories
	rm -r $(TESTDIR)/matrices/*.h

gausstest: matrix modules/linalg/gaussjordan.h
	cp -r lib/matrix/*.h $(MODULETEST)linalg/
	cp -r modules/linalg/gaussjordan.h $(MODULETEST)linalg/
	mkdir -p $(BUILDDIR)linalg/
	$(CC) $(MODULETEST)linalg/$@.c -o $(BUILDDIR)linalg/$@
	# cleaning the directories
	rm -r $(MODULETEST)linalg/*.h

cleanbuild:
	rm -r build/*
