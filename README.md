# Algorithms 

* Breadth-first fearch algorithm:

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

* Depth-first search algoritm:

```
DFS(G)
	for each vertex u in G = (V, E)
		visited[u] = WHITE
		parent[u] = NIL;
	time = 0
	for each vertex u in G = (V, E)
		if visited[u] == WHITE
			DFSvisit(G, u)
			
DFS-VISIT(G, u)
	time = time + 1
	pre[u] = time
	visited[u] = GRAY
	for each vertex v in G.adjList[u]
		if visited[v] == WHITE
			parent[v] = u
			DFS-VISIT(G, v)
	visited[u] = BLACK
	time = time + 1
	post[u] = time
```
