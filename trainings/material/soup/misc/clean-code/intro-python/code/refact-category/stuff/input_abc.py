import re
import os
from abc import ABC, abstractmethod
import pandas


class InputReader(ABC):
    @abstractmethod
    def read(self):
        assert False, 'abstract'

class SingleCSVInputReader(InputReader):
    def __init__(self, filename):
        self.filename = filename
    def read(self):
        return pandas.read_csv(
            self.filename, 
            sep=';', encoding='iso-8859-1',
            names=('account', 'info', 'time_booked', 'time_valuta', 'amount', 'unit'))

class MultipleCSVInputReader(InputReader):
    def __init__(self, filenames):
        self.readers = [SingleCSVInputReader(fn) for fn in filenames]
        
    def read(self):
        ret = pandas.DataFrame()
        for rdr in self.readers:
            ret = pandas.concat([ret, rdr.read()])
        return ret

class RecursiveCSVInputReader(InputReader):
    def __init__(self, dirname):
        self.dirname = dirname
    def read(self):
        re_yyyy_mm = re.compile(r'^\d\d\d\d-\d\d\.csv')
    
        names = []
        for name in os.listdir(self.dirname):
            if re_yyyy_mm.search(name) is not None:
                names.append(os.path.join(self.dirname, name))
    
        return MultipleCSVInputReader(names).read()

class CompositeInputReader(InputReader):
    def __init__(self, readers):
        self.readers = readers
    def read(self):
        df = pandas.DataFrame()
        for rdr in self.readers:
            df = pandas.concat([df, rdr.read()])
        return df
