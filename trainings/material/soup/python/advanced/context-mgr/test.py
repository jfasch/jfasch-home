import contextlib

@contextlib.contextmanager
def PrefixPrint(prefix):
    global print
    def myprint(*args, **kwargs):
        pfxargs = (prefix,)+args
        orig_print(*pfxargs, **kwargs)

    try:
        orig_print = print
        print = myprint
        yield
    finally:
        print = orig_print

with PrefixPrint('MEGA:'):
    print('hallo')
