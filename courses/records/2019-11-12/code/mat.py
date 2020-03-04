#!/usr/bin/env python

from scipy.io import loadmat
from sklearn.cluster import KMeans

import sys


mat = loadmat(sys.argv[1])

print(type(mat['imnData']))
print(mat['imnData'])
print(mat['imnData'].dtype)

data = mat['imnData']
