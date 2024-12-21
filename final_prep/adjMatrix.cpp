#include <iostream>
#include <queue>
using namespace std;

class AdjacencyMatrix
{
    int **graph;
    int vertices;

    void dfs(int vertex, bool visited[])
    {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < this->vertices; i++)
        {
            if(!visited[i] && graph[vertex][i] == 1)
            {
                visited[i] = true;
                dfs(i, visited);
            }
        }
    }
    public:
        AdjacencyMatrix(int vertice)
        {
            this->vertices = vertice;
            graph = new int*[this->vertices];
            for (int i = 0; i < this->vertices; i++)
            {
                graph[i] = new int[this->vertices];
            }
            for (int i = 0; i < this->vertices; i++)
            {
                for(int j = 0; j < this->vertices; j++)
                {
                    graph[i][j] = 0;
                }
            }
        }

        void performDFS(int startNode)
        {
            bool *visited = new bool[this->vertices];
            for (int i = 0; i < this->vertices; i++)
            {
                visited[i] = false;
            }
            dfs(startNode, visited);
        }

        void addEdge(int src, int dest, bool directed = false)
        {
            graph[src][dest] = 1;
            if (!directed)
            {
                graph[dest][src] = 1;
            }
        }

        void deleteEdge(int src, int dest, bool directed = false)
        {
            graph[src][dest] = 0;
            if (!directed)
            {
                graph[dest][src] = 0;
            }
        }

        void bfs(int startNode)
        {
            queue<int> q;
            bool *visited = new bool[this->vertices];
            for (int i = 0; i < this->vertices; i++)
            {
                visited[i] = false;
            }
            q.push(startNode);
            visited[startNode] = true;
            while(!q.empty())
            {
                int vertex = q.front();
                cout << vertex << " ";
                q.pop();

                for (int i = 0; i < this->vertices; i++)
                {
                    if(!visited[i] && graph[vertex][i] == 1) 
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }

        }

        void display()
        {
            for (int i = 0; i < this->vertices; i++)
            {
                for (int j = 0; j < this->vertices; j++)
                {
                    cout << graph[i][j] << " ";
                }
                cout << endl;
            }
        }

};

int main()
{
    AdjacencyMatrix graph(5);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(3, 4);

    cout << "Undirected Graph Adjacency Matrix:" << endl;
    graph.display();

    // Perform BFS from node 0
    cout << "\nBFS starting from node 0:" << endl;
    graph.bfs(0);

    cout << "\nDFS starting from node 0:" << endl;
    graph.performDFS(0);

    // Delete an edge
    cout << "\n\nDeleting edge (1, 4):" << endl;
    graph.deleteEdge(1, 4);
    graph.display();

    return 0;
}
