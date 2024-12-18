#include <iostream>
#include <queue>
using namespace std;

struct node 
{
    int vertex;
    node *next;
};

class AdjacencyList
{
    node **graph;
    int vertices;
    node *dfs(int vertex, bool visited[])
    {
        visited[vertex] = true;
        cout << vertex << " ";

        node *tmp = graph[vertex];
        while(tmp != nullptr)
        {
            int neighbour = tmp->vertex;
            if(!visited[neighbour])
            {
                visited[neighbour] = true;
                dfs(neighbour, visited);
            }
            tmp = tmp->next;
        }
    }
    public:
        AdjacencyList(int vertices)
        {
            this->vertices = vertices;
            graph = new node*[this->vertices];
            for(int i = 0; i < this->vertices; i++)
            {
                graph[i] = nullptr;
            }
        }

        void addEdge(int src, int dest, bool directed = false)
        {
            node *newNode = new node;
            newNode->vertex = dest;
            newNode->next = graph[src];
            graph[src] = newNode;

            if (!directed)
            {
                node *newnode = new node;
                newnode->vertex = src;
                newnode->next = graph[dest];
                graph[dest] = newnode;
            }
        }

        void display()
        {
            for (int i = 0; i < this->vertices; i++)
            {
                cout << i << " --> ";
                node *tmp = graph[i];
                while(tmp != nullptr)
                {
                    if(tmp->next == nullptr)
                    {
                        cout << tmp->vertex;
                    }
                    else
                    {
                        cout << tmp->vertex << " --> ";
                    }
                    tmp = tmp->next;
                }
                cout << endl;
            }
        }

        void bfs(int start)
        {
            queue<int> q;
            bool *visited = new bool[this->vertices];
            for (int i = 0; i < this->vertices; i++)
            {
                visited[i] = false;
            }

            q.push(start);
            visited[start] = true;

            while(!q.empty())
            {
                int vertex = q.front();
                cout << vertex << " ";
                q.pop();

                node *tmp = graph[vertex];
                while(tmp != nullptr)
                {
                    int neighbour = tmp->vertex;
                    if (!visited[neighbour])
                    {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                    tmp = tmp->next;
                }
            }

        }

        void PerformDFS(int start)
        {
            bool *visted = new bool[this->vertices]{false};
            dfs(start, visted);
        }


        


};

int main()
{
    AdjacencyList g(3);
    
    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);  // Optional: for a cycle in the graph

    // Display the adjacency list of the graph
    cout << "Adjacency List of the Graph:" << endl;
    g.display();
    cout << endl;

    // Perform BFS starting from vertex 0
    cout << "BFS Traversal starting from node 0: ";
    g.bfs(0);
    cout << endl;

    // Perform DFS starting from vertex 0
    cout << "DFS Traversal starting from node 0: ";
    g.PerformDFS(0);
    cout << endl;

    return 0;
}