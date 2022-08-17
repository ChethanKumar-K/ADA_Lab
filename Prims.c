#include <stdio.h>

void prims(int n,int cost[10][10]){
    int i,j,ne = 1,min,mincost=0;
    int u,v;
    int visited[10];
    for(i = 1;i<=n; i++){
        visited[i] = 0;
    }
    visited[1] = 1;
    while(ne != n){
        min = 99;
        for(i = 1; i <= n; i++){
            for(j = 1;j<= n; j++){
                if(visited[i] == 1){
                    if(cost[i][j] < min){
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if(visited[v] != 1){
            printf("%d --->  %d = %d\n",u,v,min);
            visited[v] = 1;
            mincost += min;
            ne = ne + 1;
        }
        cost[u][v] = cost[v][u] = 99;
    }
    printf("MST cost is %d\n",mincost);
}

int main()
{
    int i,j,n,cost[10][10];
	printf("Enter the no of vertices : ");
    scanf("%d",&n);
    printf("Enter cost matrix\n");
    for(i = 1; i <= n ; i++){
        for(j = 1; j<= n ; j++){
            scanf("%d",&cost[i][j]);
        }
    }
    prims(n,cost);
	return 0;
}
