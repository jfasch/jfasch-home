import asyncio

async def one_loop():
    while True:
        await asyncio.sleep(1)
        print('hallo one_loop')

async def another_loop():
    while True:
        await asyncio.sleep(1.1)
        print('hallo another_loop')

async def main():
    async with asyncio.TaskGroup() as tg:
        tg.create_task(one_loop())
        tg.create_task(another_loop())

asyncio.run(main())
