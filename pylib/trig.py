"""
wrapper for trig.h library
"""
import ctypes


def loadlibrarytrig():
    """summary:
    loads the absolute path and returns
    library
    """
    trigpath = "../build/trig/trig.so"
    triglib = ctypes.CDLL(trigpath)
    return triglib


def wrapargsret(func):
    """summary
    decarator that setup the argument types
    and the return types of the provided
    function
    """
    func.argtypes = [ctypes.double]
    func.restypes = ctypes.double

def pytrig_cos_taylor(x, func):
    return func.cos_taylor(x) 

