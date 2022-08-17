  #include <stdio.h>
int a[20][20],n;

int minInd(int visited[] , int dist[]){
    int i,mindis = 9999,minI;
    for ( i = 0; i < n ; i++){
        if(!visited[i] && dist[i] < mindis){
            mindis = dist[i];
            minI = i;
        }
    }
    return minI;
}

void dijkstra(int src){
    int i,u;
    int dist[n],visited[n];
    for(i=0 ; i < n; i++){
        visited[i] = 0;
        dist[i] = 9999;
    }
    dist[src] = 0;
    for(i = 0 ; i < n-1 ; i++){
        u = minInd(visited,dist);
        visited[u] = 1;
        printf("u is %d and distance is %d\n",u,dist[u]);
        for(int v = 0 ; v < n; v++){
            if(!visited[v] && a[u][v] != 9999 && dist[u]!= 9999 && (dist[u]+ a[u][v]) < dist[v]){
                dist[v] = dist[u] + a[u][v];
            }
        }
    }
    printf("Shortest path to all vertices from src %d is \n",src);
    printf("Vertices \t Distance from Source\n");
    for( i = 0 ; i < n ; i++){
        if( i != src){
            printf("%d\t\t %d\n",i,dist[i]);
        }
    }
}

int main()
{
    int src,i,j;
	printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("Enter the weighted matrix : \n");
    for( i = 0 ; i < n ; i ++){
        for ( j = 0; j < n; j ++){
            scanf("%d",&a[i][j]);
        }
    }
    
    printf("Enter the source vertex : ");
    scanf("%d",&src);
    dijkstra(src);
	return 0;
}
