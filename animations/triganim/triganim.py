"""
animation for the comparison of the cos data obtain from
the math.h and mathlib cos values
"""

from manim import *
import csv
import imp
import numpy as np


trig = imp.load_source('trig',"../../pylib/trig/trig.py")

class CosGraphScene(Scene):

    def construct(self):

        triglib = trig.loadlibrarytrig()
        func = trig.wrapargsret(triglib.cos_taylor)
        func_tab = trig.wrapargsret(triglib.cos_table_0_01)

        axes = Axes(
            y_range = [-2,2,1],
            x_range = [-6,6,1] 
        )

        axes.add_coordinates()
        axes_labels = axes.get_axis_labels()
        
        cos_taylor_4 = axes.plot(
                lambda x: trig.pytrig_cos(x, func),
                color = YELLOW,
                x_range = [-6,6])

        cos_table = axes.plot(
                lambda x: trig.pytrig_cos(x, func_tab),
                color = PINK,
                x_range = [-6,6])

        numpy_cos = axes.plot(lambda x: np.cos(x),
                              x_range = [-6,6],
                              color=BLUE)

        cos_taylor_label = axes.get_graph_label(
            cos_taylor_4,  label = Tex("$cos-t(4)$").scale(0.65), x_val=-10, direction=UP / 2
        )
        
        numpy_cos_label = axes.get_graph_label(numpy_cos, label=Tex("np cos").scale(0.65))

        cos_table_label = axes.get_graph_label(
            cos_table,  label = Tex("$cos-lut$").scale(0.65), x_val=-10, direction=UP / 2
        )

        plot = VGroup(axes, cos_taylor_4, numpy_cos, cos_table)
        labels = VGroup(axes_labels, cos_taylor_label, numpy_cos_label, cos_table_label)
        self.add(plot, labels)


        self.play(Write(axes))
        self.wait(5) 

class SinGraphScene(Scene):

    def construct(self):

        triglib = trig.loadlibrarytrig()
        func = trig.wrapargsret(triglib.sine_taylor)
        func_tab = trig.wrapargsret(triglib.sin_table_0_01);

        axes = Axes(
            y_range = [-2,2,1],
            x_range = [-6,6,1] 
        )

        axes.add_coordinates()
        axes_labels = axes.get_axis_labels()
        
        sin_taylor_4 = axes.plot(
                lambda x: trig.pytrig_sin(x, func),
                color = YELLOW,
                x_range = [-6,6])

        sin_table_01 = axes.plot(
                lambda x: trig.pytrig_sin(x, func_tab),
                color = PINK,
                x_range = [-6,6])

        numpy_sin = axes.plot(lambda x: np.sin(x),
                              x_range = [-6,6],
                              color=BLUE)

        sin_taylor_label = axes.get_graph_label(
            sin_taylor_4,  label = Tex("$sin-t(4)$").scale(0.65), x_val=-10, direction=UP / 2
        )
        sin_table_01_label = axes.get_graph_label(
            sin_table_01,  label = Tex("$sin-lut$").scale(0.65), x_val=-10, direction=UP / 2
        )
        numpy_sin_label = axes.get_graph_label(numpy_sin, label=Tex("np sin").scale(0.65))

        plot = VGroup(axes, sin_taylor_4, numpy_sin, sin_table_01)
        labels = VGroup(axes_labels, sin_taylor_label, numpy_sin_label, sin_table_01_label)
        self.add(plot, labels)


        self.play(Write(axes))
        self.wait(5) 
