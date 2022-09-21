# TODO
n = input("What is the height? ")
try:
    n = int(n)
except:
    n = input("What is the height?")

n = int(n)
a = 1
b = 1
for p in range(n):
    print((n - b)*" " + a * "#" + "  " + a * "#")
    a += 1
    b += 1




