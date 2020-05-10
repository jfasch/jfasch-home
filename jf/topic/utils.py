def list_of_stripped_str(optval):
    'directive option conversion'
    return [s.strip() for s in optval.split(',')]
