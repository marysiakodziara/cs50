# TODO

def is_int(n):
    try:
        n = int(n)
        if n >= 1 and n <= 8:
            return True
        else:
            return False
    except:
        return False

n = "cat"
while is_int(n) is False:
    n = input("What is the height? ")

n = int(n)
a = 1
b = 1
for p in range(n):
    print((n - b)*" " + a * "#" + "  " + a * "#")
    a += 1
    b += 1





