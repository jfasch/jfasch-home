class Matrix:
    def __init__(self, xdim, ydim):
        self._xdim = xdim
        self._ydim = ydim
        self._data = [0 for _ in range(xdim*ydim)]
    def at(self, x, y):
        return self._data[y*self._ydim + x]
    def set(self, x, y, value):
        self._data[y*self._ydim + x] = value        

m = Matrix(2,2)
m.set(1,1, 42)
print(m.at(1,1))
