#include <cs50.h>
#include <stdio.h>

float discount(float price);

int main(void)
{
    float regular = get_float("Regular Price: ");
    int percent_off = get_int("Percent off: ");
    float sale = discount(regular);
    printf("Sale Price: %.2f\n", sale);
}

float discount(float price, int percentage)
{
    return price * percentage;

}