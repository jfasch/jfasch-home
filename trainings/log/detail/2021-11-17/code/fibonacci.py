def fibo():
    first = 1
    second = 1

    yield first
    yield second

    while True:
        next = first + second
        yield next
        first = second
        second = next

if __name__ == '__main__':    # started as program
    nums = fibo()
    for i in nums:
        print(i)
