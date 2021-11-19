lin = [2,1,3,10,3,3,1,10,5,2]

lout = []
have = set()

for element in lin:
    if element not in have:
        lout.append(element)
        have.add(element)

print('outputliste:', lout)
print('have:', have)
