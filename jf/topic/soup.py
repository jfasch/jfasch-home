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
        
    def find_id(self, id):
        for t in self._topics:
            if t.id == id:
                return t
        raise KeyError('no topic with ID '+id)


def setup(app):
    app.connect('env-purge-doc', _ev_env_purge_doc)

def _ev_env_purge_doc(app, env, docname):
    app.jf_gibberish.soup.purge(docname)

    
