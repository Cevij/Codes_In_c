#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    char str[100]; /* Declares a string of size 100 */
    int l,i;
	
       printf("\n\nPrint individual characters of string :\n");
       printf("\n");
       printf("\n"); 	
       printf("Input the string : ");
       fgets(str, sizeof str, stdin);
	   l=strlen(str);
	   printf("printing char by char:\n");
       for(i=0;i<l;i++)
        {
            if(str[i]=='.')
            {
                break;
            }
            printf("%c\n", str[i]);

        }
}
