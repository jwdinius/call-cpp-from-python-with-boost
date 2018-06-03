# import our module
import pyRTP
# import numpy stuff to do unit testing
from numpy import power, e

def test_raise_e():
    rtp_e = pyRTP.Exponentiate()
    assert rtp_e.raise_to_power(2.34) == power(e, 2.34)

def test_raise_2():
    rtp_2 = pyRTP.Exponentiate(2)
    assert rtp_2.raise_to_power(1.23) == power(2, 1.23)
