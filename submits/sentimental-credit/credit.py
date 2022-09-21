# TODO

# checks for 15 numbers in cc number
int digits_num(long x)
{
    int k = 1;
    while (x > 1)
    {
        if (x > 10)
        {
            k++;
        }
        x = x / 10;
    }

    return k;
}

#lunhs algorithm
int lunhs_algorithm(long x)
{
    int sum = 0;
    for (int i = 0; x > 0; i++)
    {
        int every_other = (2 * ((x / 10) - ((x / 100) * 10)));
        int prod_digits;
        int remaining_numb = (x - ((x / 10) * 10));
        if (every_other > 9)
        {
            prod_digits = (every_other / 10) + (every_other - ((every_other / 10) * 10));
        }
        else
        {
            prod_digits = every_other;
        }

        sum = sum + prod_digits + remaining_numb;
        x = x / 100;
    }