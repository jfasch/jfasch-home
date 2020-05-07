class Soup:
    def __init__(self):
        self._topics = []
    def __len__(self):
        return len(self._topics)
    def __iter__(self):
        return iter(self._topics)
    def add(self, topic):
        self._topics.append(topic)
    def purge(self, docname):
        self._topics = [topic for topic in self._topics if topic.docname != docname]
        
