import sys


number = int(sys.argv[1])

if number == 1:
    print(number, 'is not prime')
    sys.exit(0)

for divisor in range(2, number):
    if number % divisor == 0:
        print(number, 'is not prime')
        break
else:
    print(number, 'is prime')
