#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int val;
    node *next;
};

class AdjacencyList
{
    node **AdjList;
    int vertices;
    public:
        AdjacencyList(int vertices)
        {
            this->vertices = vertices;
            AdjList = new node*[this->vertices];
            for (int i = 0; i < this->vertices; i++)
                AdjList[i] = nullptr;
        }

        void addEdge(int src, int dest, bool directed = false)
        {
            node *newNode = new node;
            newNode->val = dest;
            newNode->next = AdjList[src];
            AdjList[src] = newNode;

            if (!directed)
            {
                node *newnode = new node;
                newnode->val = src;
                newnode->next = AdjList[dest];
                AdjList[dest] = newnode;
            }
        }

        void display()
        {
            for (int i = 0; i < this->vertices; i++)
            {
                node *tmp = AdjList[i];
                cout << i << " ---> ";
                while(tmp != nullptr)
                {
                    if (tmp->next == nullptr)
                    {
                        cout << tmp->val;
                    }
                    else
                    {
                        cout << tmp->val << " ---> ";
                    }
                    tmp = tmp->next;
                }
                cout << endl;
            }
        }

                void bfs(int startPoint)
        {
            bool *visited = new bool[this->vertices];
            for (int i = 0; i < this->vertices; i++)
            {
                visited[i] = false; // Initialize all vertices as unvisited
            }

            queue<int> q; // Use int to store the vertex indices
            visited[startPoint] = true;
            q.push(startPoint);

            while (!q.empty())
            {
                int curVertex = q.front(); // Process the current vertex
                q.pop();

                cout << curVertex << " ";

                // Traverse adjacency list for the current vertex
                node *tmp = AdjList[curVertex];
                while (tmp != nullptr)
                {
                    int neighbor = tmp->val;
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        q.push(neighbor); // Push neighbor into the queue
                    }
                    tmp = tmp->next;
                }
            }

            delete[] visited; // Free memory
        }

        
};

int main()
{

    AdjacencyList g(3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.display();
    return 0;
}