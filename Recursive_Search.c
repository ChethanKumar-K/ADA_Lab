#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bin_search(int arr[],int key,int low,int high){
    int mid;
    mid=(low+high)/2;
    if(low<=high){
        if(arr[mid]==key){
            return(mid);
        }
        else if(arr[mid]>key){
            return(bin_search(arr,key,low,mid-1));
        }
        else if(arr[mid]<key){
            return(bin_search(arr,key,mid+1,high));
        }
    }
    else{
        return -1;
    }
}


int linear_search(int arr[],int key,int start,int end){
    if(start<=end){
        if(arr[start]==key){
            return(start);
        }
        else{
            return(linear_search(arr,key,start+1,end));
        }
    }
    else{
        return -1;
    }
}

int main()
{
	int n,element,position,choice;
	clock_t start_time,end_time;
	double cpu_time = 0;
    printf("Enter the number of elements in array : ");
    scanf("%d",&n);
    int arr[n];
    int lineararr[n];
    for(int i=0;i<n;i++){
        arr[i]=i;
        lineararr[i]=(rand()%1000)+i;
    }
    printf("\nElements in linear array are : ");
    for (int i=0;i<n;i++){
        printf("%d ,",lineararr[i]);
    }
    printf("\n ****  MENU  ****\n  1.Binary Search \n  2.Linear Search \n  3.Exit\n");
    printf("Enter your choice of search : ");
    scanf("%d",&choice);
    while(choice !=3){
        switch(choice){
            case 1:
                printf("Enter the element to be searched : ");
                scanf("%d",&element);
                start_time = clock();
                position = bin_search(arr,element,0,n-1);
                end_time = clock();
                cpu_time = (double) (end_time - start_time)/CLOCKS_PER_SEC;
                if(position == -1){
                    printf("Element is not found \nTime taken to execute : %f \n",cpu_time);
                }
                else{
                    printf("Element found at index : %d\nTime taken to execute : %f \n",position,cpu_time);
                }
                break;
                
                
            case 2:
                
                printf("Enter the element to be Linearly searched : ");
                scanf("%d",&element);
                start_time = clock();
                position = linear_search(lineararr,element,0,n-1);
                end_time = clock();
                cpu_time = (double) (end_time - start_time)/CLOCKS_PER_SEC;
                if(position == -1){
                    printf("Element is not found \nTime taken to execute : %f \n",cpu_time);
                }
                else{
                    printf("Element found at index %d\nTime taken to execute : %f\n",position,cpu_time);
                }
                break;
            default:
                printf("Please enter a valid choice\n");
                break;
        }
        printf("Enter your choice of search : ");
        scanf("%d",&choice);
    }
    
    return 0;
}
