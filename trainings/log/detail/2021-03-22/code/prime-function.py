import sys

def is_prime(number):
    if number == 1:
        return False
    
    for divisor in range(2, number):
        if number % divisor == 0:
            return False
    else:
        return True

n = int(sys.argv[1])
if is_prime(n):
    print(n, 'is prime')
else:
    print(n, 'is not prime')
    





