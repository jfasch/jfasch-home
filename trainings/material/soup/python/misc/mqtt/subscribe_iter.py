#!/usr/bin/env python

from paho.mqtt import client
import threading
import queue
import signal


class MQTTMessageConsumerThread(threading.Thread):
    def __init__(self, host, port, topic):
        self.client = client.Client()
        self.client.connect(host, port)
        self.client.on_message = self.on_message
        self.client.subscribe(topic)
        
        self.queue = queue.Queue()

        super().__init__()

    def iter_messages(self):
        while True:
            yield self.queue.get()

    def run(self):
        self.client.loop_forever()

    def on_message(self, client, userdata, message):
        self.queue.put(message.payload)
        
consumer = MQTTMessageConsumerThread('localhost', 1883, '/random/topic')
consumer.start()

for msg in consumer.iter_messages():
    print(msg)
