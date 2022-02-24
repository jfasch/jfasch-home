import random

seen_sixeyes = False
n_tries = 0
while n_tries < 6:
    n_tries += 1
    eyes = random.randrange(1,7)
    if eyes == 6:
        seen_sixeyes = True
        break

if seen_sixeyes:
    print('hooray!')
else:
    print('lose!')
