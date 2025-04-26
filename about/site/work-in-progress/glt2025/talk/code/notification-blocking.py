#!/usr/bin/env python3

import sdbus
from sdbus_block.notifications import FreedesktopNotifications


bus =  sdbus.sd_bus_open_user()
sdbus.default_bus.set_default_bus(bus)

notifications = FreedesktopNotifications()
notifications.notify(summary="Hello GLT2025")

