class Topic:
    def __init__(self, topicid, docname, dependencies):
        self._topicid = topicid
        self._docname = docname
        self._dependencies = dependencies
    @property
    def topicid(self):
        return self._topicid
    @property
    def docname(self):
        return self._docname
    @property
    def dependencies(self):
        return self._dependencies

