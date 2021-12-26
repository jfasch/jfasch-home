#!/usr/bin/env python3

class GooseOrDuck:
    def spend_life(self, num):
        for _ in range(num):
            self.quack()
            self.walk()


class Duck(GooseOrDuck):
    def __init__(self, height):
        self.height = height

    def quack(self):
        print('quackquackquackquackquackquack')
    def walk(self):
        print('watschelwatschelwatschelwatschelwatschelwatschel')

    def live(self):
        self.spend_life(self.height)

class Goose(GooseOrDuck):
    def __init__(self, width):
        self.width = width

    def quack(self):
        print('quackquackquackquackquackquack quackquackquackquackquackquack')
    def walk(self):
        print('watschelwatschelwatschelwatschelwatschelwatschel watschelwatschelwatschelwatschelwatschelwatschel')

    def live(self):
        self.spend_life(self.width)

goose = Goose(10)
duck = Duck(5)

goose.live()
duck.live()
