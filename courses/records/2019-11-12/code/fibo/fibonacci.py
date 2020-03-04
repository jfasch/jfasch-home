def fibo(boundary=None):
    previous = 1
    current = 1

    yield previous
    yield current

    while True:
        next = previous + current
        yield next
        if boundary and next > boundary:
            break
        previous = current
        current = next

