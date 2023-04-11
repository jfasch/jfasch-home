from led import LED
import asyncio

async def blink(interval, n, led):
    for _ in range(n):
        led.toggle()
        await asyncio.sleep(interval)

async def main():
    task1 = asyncio.create_task(blink(0.5, 10, LED('RED')))
    task2 = asyncio.create_task(blink(0.2, 30, LED('YELLOW')))
    task3 = asyncio.create_task(blink(0.4, 15, LED('GREEN')))

    await task1
    await task2
    await task3

asyncio.run(main())
