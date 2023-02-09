"""
code copied from austin henley's 
"implementation of cos" post;
"""
from math import cos,sin,pi

def generate_cos(f, PRECISION, NAME):
    f.write("double %s[] = {\n" % NAME)
    j = 0
    p = 0.0
    while True:
        f.write("{:.20f}, ".format(cos(p)))
        j += 1
        p += PRECISION
        if p > 2*pi:
            break
    f.write("1.0 };\n")
    f.write("const int %s_size = %d;\n" % (NAME, j+1))

def generate_sin(f, PRECISION, NAME):
    f.write("double %s[] = {\n" % NAME)
    j = 0
    p = 0.0
    while True:
        print(f"{p}\n")
        f.write("{:.20f}, ".format(sin(p)))
        j += 1
        p += PRECISION
        if p > 2*pi:
            break
    f.write("1.0 };\n")
    f.write("const int %s_size = %d;\n" % (NAME, j+1))


if __name__ == '__main__':
   # generate_cos(open("costable_1.h", "w"), 1.0, "costable_1")
   # generate_cos(open("costable_0_1.h", "w"), 0.1, "costable_0_1")
   # generate_cos(open("costable_0_01.h", "w"), 0.01, "costable_0_01")
   # generate_cos(open("costable_0_001.h", "w"), 0.001, "costable_0_001")
   # generate_cos(open("costable_0_0001.h", "w"), 0.0001, "costable_0_0001")
    generate_sin(open("sintable_1.h", "w"), 1.0, "sintable_1")
   # generate_sin(open("sintable_0_1.h", "w"), 0.1, "sintable_0_1")
   # generate_sin(open("sintable_0_01.h", "w"), 0.01, "sintable_0_01")
   # generate_sin(open("sintable_0_001.h", "w"), 0.001, "sintable_0_001")
   # generate_sin(open("sintable_0_0001.h", "w"), 0.0001, "sintable_0_0001")
