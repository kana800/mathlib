"""
animation for the comparison of the cos data obtain from
the math.h and mathlib cos values
"""

from manim import *
import csv
import numpy as np
import trig

class GraphScene(Scene):

    def construct(self):

        triglib = trig.loadlibrarytrig()
        func = trig.wrapargsret(triglib.cos_taylor)

        axes = Axes(
            y_range = [-2,2,1],
            x_range = [-6,6,1] 
        )

        axes.add_coordinates()
        axes_labels = axes.get_axis_labels()

        
        cos_taylor_4 = axes.plot(
                lambda x: trig.pytrig_cos_taylor(x, func),
                color = YELLOW,
                x_range = [-6,6])

        numpy_cos = axes.plot(lambda x: np.cos(x),
                              x_range = [-6,6],
                              color=BLUE)


        cos_taylor_label = axes.get_graph_label(
            cos_taylor_4,  label = Tex("$cos-t(4)$").scale(0.65), x_val=-10, direction=UP / 2
        )
        numpy_cos_label = axes.get_graph_label(numpy_cos, label=Tex("np cos").scale(0.65))

        plot = VGroup(axes, cos_taylor_4, numpy_cos)
        labels = VGroup(axes_labels, cos_taylor_label, numpy_cos_label)
        self.add(plot, labels)


        self.play(Write(axes))
        self.wait(5) 
