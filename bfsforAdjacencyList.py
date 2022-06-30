#   In this approach graph is represented as a dicitionary 
#     whose keys are the vertices and its values is the list of vertices that are connected to the key

def bfs (G,v):  #v is the start vertex
  visited = []
  Q = []
  vertex = 0
  for i in range(len(G)+1):
    visited.append(0)
  visited[v] = 1
  Q.append(v)
  print(v,end=" -> ")

  while(len(Q) != 0):
    j = Q.pop(0)
    for k in G[j]:
      if(visited[k] == 0):
        visited[k] = 1
        Q.append(k)
        print(k,end=" -> ")


graph = {}

numberOfVertices = int(input("Enter the number of vertices : "))

for i in range(1,numberOfVertices+1):
  graph[i] = []

for k in graph:
  print("Please enter the neighbours of ",k)
  elemOfk = input()
  graph[k] = [int(elemOfk[idx : idx + 1]) for idx in range(0, len(elemOfk), 1)]

startVertex = int(input("Enter the start vertex "))

bfs(graph,startVertex)
