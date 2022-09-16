from sys import exit

numbers = [4, 6, 8, 2, 7, 5, 0]

if 10 in numbers:
    print("found")
    exit(0)

print("Not found")
exit(1)