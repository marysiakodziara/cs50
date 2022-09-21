# TODO
n = input("What is the height? ")
if n != int(n):
    n = input("What is the hight?")
a = 1
b = 1
for p in range(n):
    print((n - b)*" " + a * "#" + "  " + a * "#")
    a += 1
    b += 1




