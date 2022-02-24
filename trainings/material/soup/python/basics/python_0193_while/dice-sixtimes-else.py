import random

n_tries = 0
while n_tries < 6:
    n_tries += 1
    eyes = random.randrange(1,7)
    if eyes == 6:
        print('hooray!')
        break
else:
    print('lose!')
