#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* insertionSort(int *A,int length){
    int temp,val,k;
    clock_t start_time,end_time;
	double cpu_time = 0;
    if(length <= 1){
        return (A);
    }
    else{
        start_time = clock();
        for(int i = 0;i < length -1 ; i++){
            k = i;
            for(int j = i; j< length ; j++ ){
                val = A[k];
                if(val > A[j]){
                    
                    k = j;
                    
                }
            }
            temp = A[k];
            A[k] = A[i];
            A[i] = temp;
        }
        end_time = clock();
    }
    cpu_time = (double) (end_time - start_time)/CLOCKS_PER_SEC;
    printf("Time taken %f \n",cpu_time);
    return(A);
}

int main()
{
    int count = 0,n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        arr[i] = rand()%10000;
    }
    insertionSort((int *)arr,n);
    while(count != n){
        printf("%d ,",arr[count]);
        count++;
    }
    printf("\n");
    return 0;
}
