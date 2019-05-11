#include <stdio.h>  /* for fprintf and stderr */
#include <stdlib.h> /* for exit */

int getNum(char []);
int convert(int dec);
unsigned int countSetBits(unsigned int n);

    int main()
{
    char string[100];
    int n,bin;

    printf("Enter the number\n");
    scanf("%s", &string);

    n= getNum(string);

    printf("String  = %s\nInteger = %d\n", string, n);

    bin=convert(n);

    printf("The binary equivalent is %d.\n", bin);

    printf("number of 1's: %d", countSetBits(n));

    return 0;
}
int getNum(char string[])
{
    int c, sign, offset, n;

    if (string[0] == '-')
    { // Handle negative integers
        printf("an error occured: only positive numbers\n");
        exit(0);
    }

    offset = 0;
    n = 0;

    for (c = offset; string[c] != '\0'; c++)
    {
        n = n * 10 + string[c] - '0';
    }


    return n;
}

int convert(int dec)
{
    int count=0;

    if (dec == 0)
    {
        return 0;
    }
    else
    {
        if (dec==0) {
            count++;
        }
        
        return (dec % 2 + 10 * convert(dec / 2));
    }

}

unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}