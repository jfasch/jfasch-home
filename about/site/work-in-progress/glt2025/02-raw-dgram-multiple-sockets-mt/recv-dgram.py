#!/usr/bin/env python

import socket, sys, threading

sockets = []
for name in sys.argv[1:]:
    sock = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
    sock.bind(name)
    sockets.append(sock)

def server(sock):
    while True:
        print(sock.recv(1024))

threads = []
for _ in sockets:
    th = threading.thread(server, (sock,))
    th.run()
    threads.append(th)

for th in threads:
    th.join()
