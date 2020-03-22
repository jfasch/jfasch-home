#!/usr/bin/python

from scipy.io import loadmat
import sys


mat = loadmat(sys.argv[1])

print(type(mat['imnData']))
print(mat['imnData'])
print(mat['imnData'].dtype)

# obviously "imnData" is what we want
data = mat['imnData']
# ...
