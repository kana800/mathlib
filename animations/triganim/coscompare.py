"""
animation for the comparison of the cos data obtain from
the math.h and mathlib cos values
"""

from manim import *
import csv
import numpy as np

DATAFILE = '../../data/cos_mathlib.csv'
YRANGE = []
COS_MATH_H = []
COS_MATHLIB = []

with open(DATAFILE, newline='') as csvfile:
    reader = csv.reader(csvfile, delimiter=',')
    for row in reader:
        YRANGE.append(row[0])
        COS_MATHLIB.append(row[1])


class GraphScene(Scene):

    def construct(self):
        axes = Axes(
            y_range = [-2,2,1],
            x_range = [-6,6,1] 
        )
        axes.add_coordinates()

        self.play(Write(axes))
        self.wait(1)

        curve = axes.plot(lambda x: int(float(COS_MATHLIB[x])),
                            color = YELLOW,
                            x_range = [0,4]
                          )
        #curve = axes.plot(lambda x: np.sin(x))
        self.play(Write(curve))
        self.wait(5)

