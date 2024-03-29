#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

void quicksort(int number[5000],int first,int last) 
{
    int i, j, pivot, temp;
    if( first < last ) 
    {
        pivot = first;
        i = first;
        j = last;
        while(i<j) 
        {
            while( number[i] <= number[pivot] && i < last)
                i++;
            while( number[j] > number[pivot] )
                j--;
            if(i<j)  
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);
   }
}

int main()
{
    clock_t start,end;
    int i, count, number[5000];
    printf("No. of elements: ");
    scanf("%d",&count);
    printf("Enter %d elements: ", count);
    for(i=0;i<count;i++)
    {
        number[i]=rand()%5000;
    }
    start = clock();
    quicksort(number,0,count-1);
    end = clock();
    printf("Order of Sorted elements: ");
    for(i=0;i<count;i++) 
    {
        printf(" %d",number[i]);
    }
    printf("\nSeconds taken %lf",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
