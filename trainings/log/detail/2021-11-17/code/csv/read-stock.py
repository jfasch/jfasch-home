import stock
import sys
from pprint import pprint

for record in stock.read_stock(sys.argv[1]):
    pprint(record)
