# import sys

# def my_print(*args, **kwargs):
#     indent = kwargs.pop('indent')
#     if indent is not None:
#         args = (' '*indent,) + args
#     print(*args, **kwargs)

# my_print(1, 2, 
#          end='\n(done)\n',     # <--- consumed by print
#          indent=4,             # <--- consumed by my_print
#          )

def f(*args, **kwargs):
    print(*args, **kwargs)

f(1, 2, end='\n(done)\n')
