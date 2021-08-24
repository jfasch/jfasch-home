import sys

def read_sauberes_text_file(filename):
    data = []
    f = open(filename)
    for line in f:
        # ... 
        record = (item1, ..., item13)
        data.append(record)

    return data

records = read_sauberes_text_file(sys.argv[1])
for r in records:
    # mach was mit dem quargel
