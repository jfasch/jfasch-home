#!/usr/bin/python

import sys, os, fcntl, struct

I2C_SLAVE = 0x0703 # from <linux/i2c-dev.h>

fd = os.open('/dev/i2c-1', os.O_RDWR)
fcntl.ioctl(fd, I2C_SLAVE, 0x48)

os.write(fd, '\x00')                                   # <-- register #0 will be the target of the next read operation
msb_lsb = os.read(fd, 2)                               # <-- read 2 bytes from temperature register (#0)

msb, lsb = struct.unpack('BB', msb_lsb)                # <-- convert 2 bytes ...
print float((msb<<24)|(lsb<<16)) / 65535 / 128         #     ... according to data sheet

