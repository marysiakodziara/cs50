#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float regular = get_float("Regular Price: ");
    float sale = regular 0.85;
    printf("Sale Price: %f\n", sale);
}

float discount(float price)
{
    return price * 0,85;

}