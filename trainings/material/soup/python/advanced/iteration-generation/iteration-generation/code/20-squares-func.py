def squares(seq):
    ret = []
    for i in seq:
        ret.append(i**2)
    return ret

for i in squares([1,2,3,4]):
    print(i)
