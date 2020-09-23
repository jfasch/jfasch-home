def squares(seq):
    for i in seq:
        yield i**2

for i in squares(range(1,5)):
    print(i)
