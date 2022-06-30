#  v represents the starting vertex
#  G is 2d array representation for the graph in adjacency matrix form
def bfs(G,v):
  vertex = 0 # it keeps count of the number of vertices
  Q = []    # keeps track of order in which the elements enter into the queue
  visited = []
  for i in range(len(G)):
    visited.append(0)
  visited[v] = 1
  Q.append(v)
  print(v+1,end = " -> ")
  while(len(Q) != 0):
    j = Q.pop(0)
    for k in G[j]:
      if(k == 1):
        if(visited[vertex] == 0):
          visited[vertex] = 1
          print(vertex+1,end = " -> ")
          Q.append(vertex)
      vertex += 1

#   Sample Graph      
G = [[0,1,1,0,1],[1,0,0,0,1],[1,0,0,1,1],[0,0,1,0,0],[1,1,1,0,0]]
initialVertex = int(input("Enter the start vertex : "))
#   Here vertex is decremented by one because indexing starts from zero
bfs(G,initialVertex-1)
