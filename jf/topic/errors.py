from sphinx.errors import SphinxError


class TopicError(SphinxError):
    category = 'Topic error'

class BadPath(TopicError):
    pass

class PathNotFound(TopicError):
    pass

class NotCommitted(TopicError):
    pass

class AlreadyCommitted(TopicError):
    pass
