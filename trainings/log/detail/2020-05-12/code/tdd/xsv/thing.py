class Thing:
    def __init__(self, name, initial_content):
        self.content = set(initial_content)

    def numitems(self):
        return len(self.content)

    def add(self, item):
        self.content.add(item)

    def has(self, item):
        return item in self.content
