# TODO

# checks for 15 numbers in cc number
def digits_num(x):
    k = 1
    while x > 1:
        if x > 10:
            k += 1
        x = x / 1
    return k

#lunhs algorithm
def lunhs_algorithm(x):
    sum = 0
    for i in range(x):
        every_other = (2 * ((x / 10) - ((x / 100) * 10)))
        remaining_numb = (x - ((x / 10) * 10))
        if every_other > 9:
            prod_digits = (every_other / 10) + (every_other - ((every_other / 10) * 10))
        else:
            prod_digits = every_other

        sum = sum + prod_digits + remaining_numb
        x = x / 100

