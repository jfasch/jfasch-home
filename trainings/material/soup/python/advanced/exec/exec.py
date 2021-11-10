code = 'a = 1'     # python code, available as a string (can be
                   # multiline, of course)
context = {}  # dictionary to hold any global variables that the
              # code-string will create once it is exec'd
exec(code, context)   # execute code string (compile it first)
print('value of a is:', context['a']) # see what the code string did
