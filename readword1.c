#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> // For exit()

int main(int arg, char *array[100])
{
    int flag = 0;
    int flag2 = 0;
    FILE *fptr;
    char *prt ;

    char filename[100], c;

    prt = array[1];

    sscanf(prt,"%s", filename);

    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        
        if(c != ' ' ){

            if (flag == 0)
            {
            
                printf("\nToken: ");
                flag = 1;
                flag2 = 0;

            }
            

            printf("%c", toupper(c));

        }
        
        if( c == ' ') 
        {

            if(flag2 == 0 ){

                printf("\n");
                flag2 = 1;
            }
            
            flag = 0;

        }

        if (c == '\n')
        {

            printf("\nToken: ");
            if (flag2 == 0)
            {

                printf("\n");
                
                flag2 = 1;
            }

            flag = 0;
        }

        c = fgetc(fptr);

    }

    fclose(fptr);
    return 0;
}