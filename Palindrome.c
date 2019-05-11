#include <stdio.h> 
#include <string.h> 
  

int main(int argc, char *argv[])
{ 
    char str[100], temp[100];
    int i, length = 0, flag = 0;
    char *prt;

    prt = argv[1];

    sscanf(prt,"%s",str);

    length = strnlen(str, 100);

    if(argv[2]){
        perror("Too many strings");
    }

    printf("The length of the string '%s' = %d\n", str, length);
    
    for (i = length - 1; i >= 0; i--)
    {
        temp[length - i - 1] = str[i];
    }
    /*  Check if the string is a Palindrome */

    for (flag = 1, i = 0; i < length; i++)
    {
        if (temp[i] != str[i]){
            flag = 0;
        }
    }
    if (flag == 1){

        printf("%s is a palindrome \n", str);
    }
    else{

        printf("%s is not a palindrome \n", str);
    }
    return 0;
}