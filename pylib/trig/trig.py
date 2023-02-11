"""
wrapper for trig.h library
"""
import ctypes

def loadlibrarytrig():
    """summary:
    loads the absolute path and returns
    library
    """
    #note that the trig path is relative the 
    #animation folder
    trigpath = "../../build/trig/triglib.so"
    triglib = ctypes.CDLL(trigpath)
    return triglib

def wrapargsret(func):
    """summary
    decarator that setup the argument types
    and the return types of the provided
    function
    """
    func.argtypes = [ctypes.c_double]
    func.restype = ctypes.c_double
    return func

def pytrig_cos(x, func):
    return func(x) 

def pytrig_sin(x, func):
    return func(x)
