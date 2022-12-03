import contextlib

@contextlib.contextmanager
def OpenFile(filename):
    try:
        f = open(filename)
        yield f
    except:
        raise
    else:
        f.close()

with OpenFile('/etc/passwd') as f:
    print(f.readline())

# import contextlib

# @contextlib.contextmanager
# def PrefixPrint(prefix):
#     global print 
#     orig_print = print       # <--- save away original print

#     def myprint(*args, **kwargs):
#         myargs = (prefix,) + args
#         orig_print(*myargs, **kwargs)

#     print = myprint

#     try:
#         yield                # <--- give control to user's with block
#     finally:
#         print = orig_print   # <--- restore original print

# print('not cool')            # <--- prints: "not cool"
# with PrefixPrint('MEGA:'):
#     print('super cool')      # <--- prints: "MEGA: super cool"
# print('not cool again')      # <--- prints: "not cool again"
