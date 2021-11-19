import sys
import my_csv


converted_records = my_csv.read_csv(sys.argv[1])
for r in converted_records:
    print(r)
