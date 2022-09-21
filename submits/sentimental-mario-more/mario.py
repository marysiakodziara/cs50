# TODO
n = input("What is the height? ")
try:
    n = int(n)
    while n not in range(1-8):
        n = input("What is the height?")
except:
    n = input("What is the height?")
    n = int(n)
    while n not in range(1-8):
        n = input("What is the height?")

a = 1
b = 1
for p in range(n):
    print((n - b)*" " + a * "#" + "  " + a * "#")
    a += 1
    b += 1





