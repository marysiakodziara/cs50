# TODO

n = input("What is the hight?")
while n > 8 or n < 1:
    n = input("What is the hight?")

x = n - 1
z = 1

    for i in range(n):
        for j in range(n):
            if x > j:
                print(" ")
            else:
                print("#")
        print("  ")

        # Right half
        for k in range(n):
            if z > k:
                print("#")

        print("\n")
        x = x;
        z++;

