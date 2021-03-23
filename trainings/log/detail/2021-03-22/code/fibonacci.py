def fibonacci():
    prev = cur = 1

    while True:
        yield prev

        next = prev + cur
        prev = cur
        cur = next

    
for number in fibonacci():
    print(number)
