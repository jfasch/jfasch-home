from led import LED
import asyncio

async def blink(interval, n, led):
    for _ in range(n):
        led.toggle()
        await asyncio.sleep(interval)

async def sequence():
    await asyncio.create_task(blink(0.5, 10, LED('RED')))
    await asyncio.create_task(blink(0.2, 30, LED('YELLOW')))
    await asyncio.create_task(blink(0.4, 15, LED('GREEN')))

async def main():
    await asyncio.create_task(sequence())

asyncio.run(main())
