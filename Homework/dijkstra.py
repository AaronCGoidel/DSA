def dijkstra(graph, v, s):
  distance = {}
  queue = []

  # fill queue with vertecies
  for i in range(v):
    distance[i] = float('inf')
    queue.append(i)
  distance[s] = 0 # start node is 0 away from itself

  while len(queue) > 0:
    # get vertex with min distance
    min = 0 # element's position in queue
    for vertex in range(len(queue)): 
      if distance[queue[vertex]] < distance[queue[min]]:
        min = vertex
    closest = queue[min] # vertex's ID
    queue.pop(min)

    for neighbor in range(v): # iterate over neighbors of vertex
      nextDistance = distance[closest] + graph[closest][neighbor]
      if nextDistance < distance[neighbor]:
        distance[neighbor] = nextDistance

  for elt in distance: # print distances
    print(distance[elt], end=' ')

# code to get input
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        matrix = [[0 for i in range(n)]for j in range(n)]
        c = 0
        for i in range(n):
            for j in range(n):
                matrix[i][j] = arr[c]
                c += 1
        s = int(input())
        dijkstra(matrix, n, s)
        print('')
