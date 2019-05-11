#include <stdio.h>

int main()
{
    int i, a; 
    int n = 10;
    float arr[]={7,4,2,6,54,78,95,12,51,85};
    float temp[10];

    for (i = 0; i < n; ++i) 
        {
 
            for (int j = i + 1; j < n; ++j)
            {
 
                if (arr[i] < arr[j]) 
                {
 
                    a =  arr[i];
                    arr[i] = arr[j];
                    arr[j] = a;
 
                }
 
            }
 
        }

    for (i=0;i<10;i++)
    {
        printf("%.2f \n", arr[i]);
    }
    return 0;
}