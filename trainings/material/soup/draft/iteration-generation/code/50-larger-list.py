inputlist = []

print('filling input list')

cnt = 0
while cnt < 10000000:
    inputlist.append(cnt)
    cnt += 1

print('calculating squares')

for i in [i**2 for i in inputlist]:
    print(i)
