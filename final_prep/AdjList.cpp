#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int val;
    node *next = nullptr;
};

class Graph
{
    node **graph;
    int vertices;

    void dfs(int startNode, bool visited[])
    {
        visited[startNode] = true;
        node *cur = graph[startNode];
        cout << startNode << " ";

        while(cur != nullptr)
        {
            int i = cur->val;
            if(!visited[i])
            {
                dfs(i, visited);
            }
            cur = cur->next;
        }
    }
    public:
    Graph(int v)
    {
        vertices = v;
        graph = new node*[vertices];
        for (int i = 0; i < vertices; i++)
        {
            graph[i] = nullptr;
        }
    }

    void addEdge(int src, int dest, bool directed = false)
    {
        node *newNode = new node;
        newNode->val = dest;
        newNode->next = graph[src];
        graph[src] = newNode;

        if(!directed)
        {
            node *newNode = new node;
            newNode->val = src;
            newNode->next = graph[dest];
            graph[dest] = newNode;
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

    void deleteEdge(int src, int dest, bool directed = false)
    {
        node *cur = graph[src], *prev = nullptr;
        while(cur != nullptr && cur->val != dest)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr)
        {
            return;
        }
        else
        {
            if(prev == nullptr)
            {
                graph[src] = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }
            delete cur;
        }

        if(!directed)
        {
            node *cur = graph[dest], *prev = nullptr;
            while(cur != nullptr && cur->val != src)
            {
                prev = cur;
                cur = cur->next;
            }
            if (cur == nullptr)
            {
                return;
            }
            else
            {
                if(prev == nullptr)
                {
                    graph[dest] = cur->next;
                }
                else
                {
                    prev->next = cur->next;
                }
                delete cur;
            }   
        }

    }

    void display()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << i << " : ";
            node *cur = graph[i];
            while(cur != nullptr)
            {
                if (cur->next == nullptr)
                {
                    cout << cur->val;
                }
                else
                {
                    cout << cur->val << " --> ";
                }
                cur = cur->next;
            }
            cout << endl;
        }
    }

    void bfs(int startNode)
    {
        queue<int> q;
        bool *visited = new bool[vertices];
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

            node *cur = graph[vertex];
            while(cur != nullptr)
            {
                int i = cur->val;
                if (!visited[i])
                {
                    visited[i] = true;  
                    q.push(i);
                }
                cur = cur->next;
            }
        }
    }


};

int main()
{

    Graph g(5);

    // Add edges between vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "Adjacency List before deleting edges:" << endl;
    g.display();

    cout << "\nDeleting edge between vertex 0 and 2..." << endl;
    // g.deleteEdge(0,2);

    cout << "Final graph:" << endl;
    g.display();
    cout << "\nBFS: ";
    g.bfs(0);

    cout << "\nDFS: ";
    g.performDFS(0);
}