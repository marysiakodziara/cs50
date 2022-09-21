# TODO

def is_int(n):
    try:
        n = int(n)
        return True
    except:
        return False
def in_range(n):
    
n = "cat"
while is_int(n) is False:
    n = input("What is the height? ")


a = 1
b = 1
for p in range(n):
    print((n - b)*" " + a * "#" + "  " + a * "#")
    a += 1
    b += 1





