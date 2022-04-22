class MyTable:
    def __init__(self, table):
        self._table = table
    def umsatz_summe(self):
        s = 0
        for k, v in self._table.items():
            s += v['umsatz']
        return s
    def mengen_durchschnitt(self):
        l = []
        for k, v in self._table.items():
            menge = v['menge']
            l.append(menge)
        return sum(l)/len(l)
