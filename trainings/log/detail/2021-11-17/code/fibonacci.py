def fibo():
    '''
    Generate the *infinite* fibonacci sequence. Note that we use the
    ``yield`` statement and not ``return`` - this makes this a
    *generator* which is fundamentally different from a *function*.
    '''

    first = second = 1

    yield first
    yield second

    while True:
        next = first + second
        yield next
        first, second = second, next

if __name__ == '__main__':    # started as program, and not imported
    nums = fibo()
    for i in nums:
        print(i)
