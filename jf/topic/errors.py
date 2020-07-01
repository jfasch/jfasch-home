from sphinx.errors import SphinxError


class TopicError(SphinxError):
    category = 'Topic error'

class NotPath(TopicError):
    pass

class NotCommitted(TopicError):
    pass

class AlreadyCommitted(TopicError):
    pass
