from stuff.conversions import clean_data
from stuff.input_abc import SingleCSVInputReader, RecursiveCSVInputReader, CompositeInputReader
from stuff.output import write_to_csv
from stuff.category import categorize

import sys
import os

INPUTS = sys.argv[1:-1]
OUTPUTFILE = sys.argv[-1]

readers = []
for i in INPUTS:
    if not os.path.exists(i):
        assert False
    if os.path.isfile(i):
        readers.append(SingleCSVInputReader(i))
    elif os.path.isdir(i):
        readers.append(RecursiveCSVInputReader(i))
    else:
        assert False

reader = CompositeInputReader(readers)
data = reader.read()
data = clean_data(data)
data = categorize(data)
write_to_csv(data, OUTPUTFILE)

