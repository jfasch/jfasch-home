import matplotlib.pyplot as plt

x = [1, 2, 3, 4]
y = [i**2 for i in x]

plt.plot(x, y)
plt.ylabel('squares')
plt.show()
