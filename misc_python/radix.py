"""
radix.py
because everyone is always talking about it, I thought I would try to
implement what I have inferred that it is.
For simplicity this will be a binary radix sort for positive integers.
It is definitely linear, but slow. on 10^7 ints < 1024, it takes a minute
"""
import math
import time
import random


def radix(inlist):
    """
    :param inlist: a list of non-negative integers
    :return: The integers, in sorted order (hopefully in linear time)
    """
    maxlog = 0
    # See how many iterations will be necessary
    for item in inlist:
        maxlog = max(maxlog,int(math.log(item+1, 2)))
    lowlist = []
    highlist = []
    for i in range(maxlog + 1):
        for item in inlist:
            if (item//2**i)%2 == 0:
                lowlist.append(item)
            else:
                highlist.append(item)
        inlist = lowlist + highlist
        lowlist.clear()
        highlist.clear()
    return inlist

def genlist(listlen):
    """
    :param listlen: the length of the list to be generated
    :return: A list of random large integers
    """
    outlist = []
    maxval = 2**10
    for i in range(listlen):
        outlist.append(random.randrange(maxval))
    return outlist

if __name__ == '__main__':
    for listlen in [1000,10000,100000,1000000,10000000]:
        inlist = genlist(listlen)
        inlist2 = inlist.copy()
        starttime = time.clock()
        radix(inlist)
        endtime = time.clock()
        print(endtime - starttime)

