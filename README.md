# Algorithms 

* Breadth-First Search algorithm:

```
BFS(G,s)
	bool visited[G.V]
	QUEUE Q = EMPTY
	for each vertex u in G = (V, E) - {s}
		visited[u] = false
	visited[s] = true
	ENQUEUE(Q, s)
	while Q not EMPTY
		u = DEQUEUE(Q)
		for each vertex v in G.adjList[u]
			if visited[v] = false
				ENQUEUE(Q, v)
		visited[u] = true
```
