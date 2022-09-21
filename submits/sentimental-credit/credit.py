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
