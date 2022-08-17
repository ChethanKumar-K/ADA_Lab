#include <stdio.h>

// Program to find minimum distance between pair of vertices in a graph

int a[30][30],n;

void Floyd(int src){
    int D[n][n];
    for(int i = 0; i < n ; i++){
        for(int j=0 ; j <n ; j++){
            D[i][j] = a[i][j];
        }
    }
    for(int k = 0; k < n ; k++){
        for(int i = 0; i< n ; i++){
            for(int j=0 ; j < n ; j++){
                D[i][j] = (D[i][j] > D[i][k]+D[k][j]) ? D[i][k]+D[k][j] : D[i][j];
            }
        }
    }
    for(int i= 1 ; i <= n ; i++){
        printf("\t%d",i);
    }
    printf("\n");
    for(int i =0; i < n ; i++){
        printf("%d",i+1);
        for (int j =0 ; j < n ; j++){
            printf("\t%d",D[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int src;
	printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix \n");
    for(int i =0; i < n ; i++){
        for (int j =0 ; j < n ; j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the source vertex : ");
    scanf("%d",&src);
    Floyd(src);
    
	return 0;
}
