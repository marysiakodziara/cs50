# TODO
n = input("What is the height? ")
while True:
    try:
        n = int(n)
        while n not in range(1-8):
            n = input("What is the height?")
    except:
        True
    else:
        break

a = 1
b = 1
for p in range(n):
    print((n - b)*" " + a * "#" + "  " + a * "#")
    a += 1
    b += 1





