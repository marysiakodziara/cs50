# TODO
n = get_int_input("What is the height? ")
while n > 8 or n < 1:
    n = get_int_input("What is the height? ")

a = 1
b = 1
for p in range(n):
    print((n - b)*" " + a * "#" + "  " + a * "#")
    a += 1
    b += 1





