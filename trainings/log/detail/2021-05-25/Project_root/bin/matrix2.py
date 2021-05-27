# Ex. 2 Class Matrix
import os.path

import sys
print(sys.path)

# sys.path.insert(1, r'..\lib') Variante 1
sys.path.insert(1, os.path.join('..', 'lib'))

import matutil.matrix

tab_m= matutil.matrix.Matrix(r'C:\Users\Student\20210525_SEO\2009_results_Tab_1.csv')

m_A2 = tab_m.extract('A2')
m_A3 = tab_m.extract('A3')

print(m_A3)
