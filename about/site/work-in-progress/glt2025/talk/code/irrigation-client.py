#!/usr/bin/env python3

from irrigation.dbus_interfaces import DBusIrrigationSystem, DBusIrrigator

import sdbus
import asyncio
from pprint import pprint


irrigation_system = DBusIrrigationSystem.new_proxy(
    bus = sdbus.sd_bus_open_user(),
    service_name = 'me.faschingbauer.IrrigationService',
    object_path = '/me/faschingbauer/IrrigationSystem')
irrigators = {}

async def status_loop():
    while True:
        for name, irrigator in irrigators.items():
            name = await irrigator.Name
            low = await irrigator.Low
            high = await irrigator.High
            moisture_value = await irrigator.MoistureValue 
            switch_state = await irrigator.SwitchState

            print(f'name {name}: low {low}, high {high}, moisture_value {moisture_value}, switch_state {switch_state}')

        await asyncio.sleep(1)

async def report_switches_changed():
    async for event in irrigation_system.SwitchStateChanged:
        print(event)

async def main():
    names = await irrigation_system.GetIrrigatorNames()
    for name in names:
        irrigators[name] = DBusIrrigator.new_proxy(
            bus = sdbus.sd_bus_open_user(),
            service_name = 'me.faschingbauer.IrrigationService',
            object_path = f'/me/faschingbauer/IrrigationSystem/{name}')

    async with asyncio.TaskGroup() as tg:
        tg.create_task(status_loop())
        tg.create_task(report_switches_changed())

asyncio.run(main())
