print('creating input range')

inputrange = range(10000000)

print('calculating squares')

for i in [i**2 for i in inputrange]:
    print(i)
