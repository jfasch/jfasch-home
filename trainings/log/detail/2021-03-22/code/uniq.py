def uniq(seq):
    have = set()
    ret_l = []
    for element in seq:
        if element not in have:
            ret_l.append(element)
            have.add(element)
    return ret_l

l = [4, 2, 4, 5, 6, 7, 8, 4, 2, 8, 9]

uniq_l = uniq(l)

for i in uniq_l:
    print(i)

# 4
# 2
# 5
# 6
# 7
# 8
# 9
