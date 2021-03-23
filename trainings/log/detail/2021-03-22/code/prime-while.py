import sys


number = int(sys.argv[1])

if number == 1:
    print(number, 'is not prime')
    sys.exit(0)

divisor = 2

while divisor < number:
    if number % divisor == 0:
        print(number, 'is not prime')
        break

    divisor += 1
else:
    print(number, 'is prime')
