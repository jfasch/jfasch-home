#!/usr/bin/python3


input_numbers = [1,2,3,4]

def squares(numbers):
    '''return a list containing the squares of the numnbers from the input
    sequence

    '''

    list_of_squares = []
    for i in numbers:
        list_of_squares.append(i**2)
    return list_of_squares

print('dumb function: squares({})'.format(input_numbers))
for i in squares(input_numbers):
    print(i)

# for such simple things as square numbers, use a list
# comprehension. this makes the code shorter - you omit a function
# definition.
print('list compehension: [n**2 for n in {}]'.format(input_numbers))
for i in [n**2 for n in input_numbers]:
    print(i)

# list comprehensions still allocate memory to hold the list. with
# minimal effort, you can save that allocation by transforming the
# list comprehension into a generator expression.
print('generator expression: (n**2 for n in {})'.format(input_numbers))
for i in (n**2 for n in input_numbers):
    print(i)
