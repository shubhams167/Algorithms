# Algorithms 

* Breadth-first search algorithm:

```
BFS(G,s)
	for each vertex u in G = (V, E) - {s}
		visited[u] = WHITE
		distance[u] = INF
		parent[u] = NIL
	visited[s] = GRAY
	parent[s] = NIL
	distance[s] = 0
	ENQUEUE(Q, s)
	while Q not EMPTY
		u = DEQUEUE(Q)
		for each vertex v in G.adjList[u]
			if visited[v] = WHITE
				visited[v] = GRAY
				parent[v] = u
				distance[v] = distance[u] + 1
				ENQUEUE(Q, v)
		visited[u] = true
```

* Depth-first search algorithm:

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
