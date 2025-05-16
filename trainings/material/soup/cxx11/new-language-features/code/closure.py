def create_print_function(message):
    def print_message():
        print(message)   # <--- message is 'in the closure of function object "print_message"'
    return print_message

p = create_print_function('howdy')
p()
