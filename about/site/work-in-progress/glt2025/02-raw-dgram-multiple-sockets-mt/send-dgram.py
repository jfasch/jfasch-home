#!/usr/bin/env python

import socket, sys

sock = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)

while True:
    msg = input('message (utf-8 please): ')
    sock.sendto(msg.encode(encoding='utf-8'), sys.argv[1])
