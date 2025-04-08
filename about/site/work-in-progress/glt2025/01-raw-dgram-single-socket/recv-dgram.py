#!/usr/bin/env python

import socket


sock = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
sock.bind('/tmp/incoming')

while True:
    print(sock.recv(1024))

# socket.fileno()
