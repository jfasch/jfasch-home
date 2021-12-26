#!/usr/bin/env python3

class GooseOrDuck:
    def __init__(self, num):
        self.num = num

    def live(self):
        for _ in range(self.num):
            self.quack()
            self.walk()


class Duck(GooseOrDuck):
    def __init__(self, height):
        super().__init__(height)

    def quack(self):
        print('quackquackquackquackquackquack')
    def walk(self):
        print('watschelwatschelwatschelwatschelwatschelwatschel')

class Goose(GooseOrDuck):
    def __init__(self, width):
        super().__init__(width)

    def quack(self):
        print('quackquackquackquackquackquack quackquackquackquackquackquack')
    def walk(self):
        print('watschelwatschelwatschelwatschelwatschelwatschel watschelwatschelwatschelwatschelwatschelwatschel')

goose = Goose(10)
duck = Duck(5)

goose.live()
duck.live()
