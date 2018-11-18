#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph
{
	private:
		int n;
		vector<vector<int>> adjList;
		enum color{	WHITE, GRAY, BLACK};
		vector<color> visited;
		vector<int> parent, distance;
	public:
		Graph(int N) : n(N) 
		{
			adjList.resize(n);//Create n vertices		
			visited.resize(n);
			parent.resize(n);
			distance.resize(n);
		}
		
		/*Function to add a directed edge between vertex v1 and v2*/
		void addEdge(int v1, int v2)
		{
			adjList[v1].push_back(v2);
		}
		
		/*Function to perform Breadth-First Search on graph G from a source vertex s*/
		void BFS(const int s)
		{
			/*Set up the visited vector to keep track of vertices which have been visited*/
			for(int u = 0; u < n; u++)
			{
				visited[u] = WHITE;//Color vertex u as WHITE i.e. not visited
				parent[u] = -1;
			}
			/*Set up a queue to have vertices which are pending to be visited*/
			queue<int> Q;
			distance[s] = 0;//Distance of vertex s from vertex s is 0
			parent[s] = -1;//Vertex s has no parent	
			visited[s] = GRAY;//Color source vertex as GRAY(i.e., pending)
			cout<<"Vertex "<<s<<" has been colored as GRAY,  with distance from source vertex "<<s<<" is: "<<distance[s]<<endl;
			Q.push(s);//Push the source vertex into the queue as it is currently in pending of to be visited
			while(!Q.empty())//While queue is not empty, if queue becomes empty then we are done traversing
			{
				int u = Q.front();Q.pop();//Dequeue a pending vertex from the queue to visit it
				for(int i = 0; i < adjList[u].size(); i++)//For each vertex v, in the adjacency list, which is connected to u
				{
					int v = adjList[u][i];//v is a vertex connected to u
					if(visited[v] == WHITE)
					{
						visited[v] = GRAY;//Color vertex v as GRAY(i.e., pending)
						parent[v] = u;//u is parent of vertex v
						distance[v] = distance[u] + 1;//Distance of vertex v from source vertex s is (distance of source vertex from v's parent vertex + 1)
						cout<<"Vertex "<<v<<" has been colored as GRAY,  with distance from source vertex "<<s<<" is: "<<distance[v]<<endl;
						Q.push(v);//Enqueue a vertex v to keep it pending to visit
					
					}
				}
				visited[u] = BLACK;//Color u as Black(i.e., visited) as it has been completely visited
				cout<<"Vertex "<<u<<" has been colored as BLACK, with distance from source vertex "<<s<<" is: "<<distance[u]<<endl;
			}
		}
		/*Function to print shortest path from source vertex s to vertex v assuming BFS(s) has already been done*/
		void printPath(int s, int v)
		{
			if(v == s)
				cout<<s<<" ";
			else if(parent[v] == -1)
					cout<<"No path from vertex "<<s<<" to vertex "<<v<<endl;
			else
			{
				printPath(s, parent[v]);
				cout<<v<<" ";
			}
		}
};

int main()
{
	Graph G(8);
	const int source = 1;
	/*Add edges between vertices*/
	G.addEdge(0, 1);
    G.addEdge(0, 4);
    G.addEdge(1, 0);
    G.addEdge(1, 5); 
    G.addEdge(2, 3); 
    G.addEdge(2, 5); 
    G.addEdge(2, 6);
    G.addEdge(3, 2); 
    G.addEdge(3, 6); 
    G.addEdge(3, 7);
    G.addEdge(4, 0);
    G.addEdge(5, 1); 
    G.addEdge(5, 2); 
    G.addEdge(5, 6);
    G.addEdge(6, 5); 
    G.addEdge(6, 2); 
    G.addEdge(6, 3);
    G.addEdge(6, 7); 
    G.addEdge(7, 6);
    G.addEdge(7, 3);
    G.BFS(source);//Perform BFS from a sources vertex
    G.printPath(source, 6);
	return 0;
}
