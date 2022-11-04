import numbers

class Number:
    def __init__(self, n):
        self.n = n
    def __sub__(self, other):
        if isinstance(other, Number):
            return Number(self.n - other.n)
        elif isinstance(other, numbers.Number):
            return Number(self.n - other)
        else:
            return NotImplemented
    def __rsub__(self, other):
        if isinstance(other, Number):
            return Number(other.n - self.n)
        elif isinstance(other, numbers.Number):
            return Number(other - self.n)
        else:
            return NotImplemented


# sum = Number(1) + 2
# print(sum.n)

l = 1
r = Number(2)

diff = l - r

print(diff.n)
