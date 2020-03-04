import numpy as np


def load_dat(filename):
    '''load a .dat file (whatever that is) into a numpy matrix and returns
    that matrix.
    '''

    matrix_lines = []

    with open(filename) as f:
        for line in f:
            if '----- ----- ----- ----- -----' in line:
                matrix_lines = f.readlines()
                break
        else:
            raise RuntimeError('file format vergeigt')

    # split matrix_lines into elements
    matrix_elements = []
    for l in matrix_lines:
        if len(l.strip()) == 0:
            continue
        elems = l.split()
        del elems[0] # line-number column, unnecessary
        matrix_elements.append(elems)

    # determine dimensions of (triangular?) matrix 
    x = len(matrix_elements)
    y = max((len(l) for l in matrix_elements))

    matrix = np.zeros((x,y))
    for row_no, row in enumerate(matrix_elements):
        matrix[row_no,0:len(row)] = row

    return matrix
