#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*Function to perform Breadth-First Search on a graph G from a source vertex s*/
void BFS(const vector<vector<int>> &G, const int s)
{
	/*Set up the visited vector to keep track of vertices which have been visited*/
	vector<bool> visited(G.size());
	for(int i = 0; i < visited.size(); i++)
	{
		visited[i] = false;
	}
	/*Set up a queue to have vertices which are pending to be visited*/
	queue<int> Q;	
	visited[s] = true;//Mark source vertex as visited, obviously!
	Q.push(s);//Push the source vertex into the queue as it is currently in pending of to be visited
	while(!Q.empty())//While queue is not empty, if queue becomes empty then we are done traversing
	{
		int u = Q.front();Q.pop();//Dequeue a pending vertex from the queue to visit it
		cout<<u<<" ";//Print the queue currently visiting
		for(int i = 0; i < G[u].size(); i++)//For each vertex v, in the adjacency list, which is connected to u
		{
			int v = G[u][i];//v is a vertex connected to u
			if(!visited[v])
			{
				Q.push(v);//Enqueue a vertex v to keep it pending to visit
			}
		}
		visited[u] = true;//Mark u as visited as it has been completely visited
	}
}

/*Function to add an edge through vertex u and v in an undirected graph G*/
void addEdge(vector<vector<int>> &G, const int u, const int v)
{
	G[u].push_back(v);//Connect an edge from vertex u to vertex v
	G[v].push_back(u);//Connect an edge from vertex v to vertex u
}

int main()
{
	int v = 8;//Number of vertices
	const int source = 3;
	vector<vector<int>> G(v);//Construct a Graph having v vertices and 0 edges for now, using adjacency list representation
	/*Add edges between vertices*/
	addEdge(G, 0, 1); 
    addEdge(G, 0, 2); 
    addEdge(G, 7, 3); 
    addEdge(G, 1, 4); 
    addEdge(G, 2, 5); 
    addEdge(G, 2, 6);
    
    BFS(G, source);//Perform BFS from a sources vertex
	return 0;
}
