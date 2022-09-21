# TODO
n = input("What is the height? ")
try:
    if n != int(n):
        n = input("What is the hight?")
except:
    n = input("What is the height?")

n = int(n)
a = 1
b = 1
for p in range(n):
    print((n - b)*" " + a * "#" + "  " + a * "#")
    a += 1
    b += 1




