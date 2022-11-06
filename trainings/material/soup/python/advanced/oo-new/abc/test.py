import abc

class Sensor(abc.ABC):
    @abc.abstractmethod
    def get_temperature(self):
	return -273.5   # implementations should return float
        

class ConstantSensor(Sensor):
    def __init__(self, value):
        self.value = value

    def get_temperature(self):
        return self.value

import random
class RandomSensor(Sensor):
    def __init__(self, lo, hi):
        self.lo = lo
        self.hi = hi

    def get_temperature(self):
        return random.uniform(self.lo, self.hi)

class BrokenSensor(Sensor):
    def getTemperature(self):               # <--- broken, should be get_temperature()
        return -273.15

sensors = {
    'my-const': ConstantSensor(36.5),
    'my-broken': BrokenSensor(),            # <--- instantiate
}

for i in range(5):
    for name, s in sensors.items():
        temperature = s.get_temperature()   # <--- broken duck
        print(f'#{i} {name}: {temperature}')
