#include<iostream>
#include<vector>

using namespace std;

class Graph
{
	private:
		int n, time;
		vector<vector<int>> adjList;
		enum color{	WHITE, GRAY, BLACK};
		vector<color> visited;
		vector<int> parent, pre, post;
	public:
		Graph(int N) : n(N) 
		{
			adjList.resize(n);//Create n vertices		
			visited.resize(n);
			parent.resize(n);
			pre.resize(n);
			post.resize(n);
		}
		/*Function to add a directed edge between vertex v1 and v2*/
		void addEdge(int v1, int v2)
		{
			adjList[v1].push_back(v2);
		}
		/*Helper function to perform DFS on every vertex*/
		void DFS()
		{
			for(int u = 0; u < n; u++)
			{
				parent[u] = -1;//Set parent of vertex u to be -1
				visited[u] = WHITE;//Color vertex u as WHITE i.e. not visited
			}
			time = 0;
			for(int u = 0; u < n; u++)
				if(visited[u] == WHITE)
					DFSvisit(u);
		}
		/*Recursive function to perform DFS from vertex u*/
		void DFSvisit(int u)
		{
			time++;//Increment time since vertex u has just been discovered
			pre[u] = time;
			visited[u] = GRAY;//Mark u as pending
			//cout<<"Vertex "<<u<<" marked as GRAY\n";
			for(int v = 0; v < adjList[u].size(); v++)
				if(visited[adjList[u][v]] == WHITE)
				{
					parent[v] = u;
					DFSvisit(adjList[u][v]);
				}
			visited[u] = BLACK;//u has been completely visited now
			time++;
			post[u] = time;
			cout<<"Vertex "<<u<<"("<<pre[u]<<"/"<<post[u]<<") marked as BLACK\n";
		}
};


int main()
{
	Graph g(6);
	g.addEdge(0, 1); 
    g.addEdge(0, 3); 
    g.addEdge(1, 4); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
    g.addEdge(3, 1);
	g.addEdge(4, 3);
	g.addEdge(5, 5); 
    g.DFS();//Perform DFS
	return 0;
}
