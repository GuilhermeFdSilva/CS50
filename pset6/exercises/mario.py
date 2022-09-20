from cs50 import get_int

def height():
    while True:
        n = get_int("Height: ")
        if n > 0 and n <= 8:
            break
    return n

def pyramid(n):
    hash = n - (n - 1)
    dot = n - 1
    for i in range(n):
        print(" " * dot + "#" * hash)
        hash += 1
        dot -= 1

height = height()
pyramid(height)