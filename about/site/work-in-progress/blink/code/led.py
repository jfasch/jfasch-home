class LED:
    def __init__(self, name):
        self.name = name
        self.state = False
    def set(self, state):
        if state != self.state:
            self.state = state
            print(self.name, self.state)
    def toggle(self):
        self.set(not self.state)
