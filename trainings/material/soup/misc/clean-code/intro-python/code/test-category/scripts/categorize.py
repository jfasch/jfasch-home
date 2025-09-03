from stuff.conversions import clean_data
from stuff.input import read_from_csv_dir
from stuff.output import write_to_csv
from stuff.category import categorize

import sys

INPUTDIR = sys.argv[1]
OUTPUTFILE = sys.argv[2]

data = read_from_csv_dir(INPUTDIR)
data = clean_data(data)
data = categorize(data)
write_to_csv(data, OUTPUTFILE)

