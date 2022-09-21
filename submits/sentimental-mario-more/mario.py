# TODO

n = input("What is the height? ")
if isdigit(n):
    while n > 8 or n < 1:
        int(n)
        a = 1
        b = 1
    for p in range(n):
        print((n - b)*" " + a * "#" + "  " + a * "#")
        a += 1
        b += 1
else:
    exit()