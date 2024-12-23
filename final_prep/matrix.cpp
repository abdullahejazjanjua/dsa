#include <iostream>
#include <queue>
using namespace std;

class graph
{
    int **matrix;
    int vertices;

    void dfs(int vertex, bool *visited)
    {
        cout << vertex << " ";
        visited[vertex] = true;
        for (int j = 0; j < vertices; j++)
        {
            if(matrix[vertex][j] == 1 && !visited[j])
            {
                dfs(j, visited);
            }
        }
    }
    public:
        graph(int v)
        {
            vertices = v;
            matrix = new int*[vertices];
            for (int i = 0; i < vertices; i++)
            {
                matrix[i] = new int[vertices];
            }

            for (int i = 0; i < vertices; i++)
            {
                for (int j = 0; j < vertices; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        void performDFS(int startNode)
        {
            bool *visited = new bool[vertices];
            for (int i = 0; i < vertices; i++)
            {
                visited[i] = false;
            }
            dfs(startNode, visited);
        }
        void addEdge(int src, int dest, bool directed = false)
        {
            matrix[src][dest] = 1;
            if(!directed)
            {
                matrix[dest][src] = 1;
            }
        }

        void deleteEdge(int src, int dest, bool directed = false)
        {
            matrix[src][dest] = 0;
            if(!directed)
            {
                matrix[dest][src] = 0;
            }
        }

        void display()
        {
            for (int i = 0; i < vertices; i++)
            {
                for (int j = 0; j < vertices; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        void bfs(int startNode)
        {
            bool *visited = new bool[vertices];
            queue<int> q;
            for (int i = 0; i < vertices; i++)
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

                for(int j = 0; j < vertices; j++)
                {
                    if(!visited[j] && matrix[vertex][j] == 1)
                    {
                        visited[j] = true;
                        q.push(j);
                    }
                }

            }
        }
};

int main()
{
    graph graph(5);

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