from cs50 import get_float

def mony():
    while True:
        n = get_float("Change owed: ")
        if n > 0:
            break
    return n

def coins(n):
    n = int(n *100)
    coins = 0
    while (n - 25) >= 0:
        coins += 1
        n -= 25
    while (n - 10) >= 0:
        coins += 1
        n -= 10
    while (n - 5) >= 0:
        coins += 1
        n -= 5
    while (n - 1) >= 0:
        coins += 1
        n -= 1
    print(coins)

mony = mony()
coins(mony)