class well_ordered_dict:
    def __init__(self):
        self.by_index = {}
        self.by_name = {}

    def add(self, elem):
        index, name, data = elem
        self.by_index[index] = elem
        self.by_name[name] = elem

    def get_by_index(self, index):
        elem = self.by_index.get(index)
        assert elem is not None
        idx, name, data = elem
        return data, name

    def get_by_name(self, name):
        elem = self.by_name.get(name)
        assert elem is not None
        idx, name, data = elem
        return data, idx
