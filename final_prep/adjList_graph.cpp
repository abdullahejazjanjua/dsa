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
    node **Adjlist;
    int vertices;

    void dfs(int vertex, bool visited[])
    {
        visited[vertex] = true;
        cout << vertex << " ";
        node *cur = Adjlist[vertex];
        while(cur != nullptr)
        {
            int neighbour = cur->val;
            if (!visited[neighbour])
            {
                dfs(cur->val, visited);
            }
            cur = cur->next;
        }

    }
    public:
        void performDFS(int startnode)
        {
            bool *visited = new bool[this->vertices];
            for (int i = 0; i < this->vertices; i++)
            {
                visited[i] = false;
            }
            dfs(startnode, visited);
            
        }
        AdjacencyList(int vertices)
        {
            Adjlist = new node*[vertices];
            for (int i = 0; i < vertices; i++)
                Adjlist[i] = nullptr;

            this->vertices = vertices;
        }

        void addEdge(int src, int dest, bool directed = false)
        {
            node *newNode = new node;
            newNode->val = dest;
            newNode->next = Adjlist[src];
            Adjlist[src] = newNode;

            if(!directed)
            {
                node *newNode = new node;
                newNode->val = src;
                newNode->next = Adjlist[dest];
                Adjlist[dest] = newNode;
            }
        }

        void deleteEdge(int src, int dest, bool directed = false)
        {
            node *cur = Adjlist[src], *prev = nullptr;

            while(cur != nullptr && cur->val != dest)
            {
                prev = cur;
                cur = cur->next;
            }
            if (cur == nullptr)
            {
                cout << "\nThere is no connection from " << src << " to " << dest << endl; 
            }
            else
            {
                if (prev == nullptr)
                {
                    Adjlist[src] = cur->next;
                }
                else
                {
                    prev->next = cur->next;
                }

                delete cur;
            }

            if(!directed)
            {
                node *cur = Adjlist[dest], *prev = nullptr;

                while(cur != nullptr && cur->val != src)
                {
                    prev = cur;
                    cur = cur->next;
                }
                if (cur == nullptr)
                {
                    cout << "\nThere is no connection from " << src << " to " << dest << endl; 
                }
                else
                {
                    if (prev == nullptr)
                    {
                        Adjlist[dest] = cur->next;
                    }
                    else
                    {
                        prev->next = cur->next;
                    }

                    delete cur;
                }
            }  
        }

        void bfs(int startNode)
        {
            bool *visited = new bool[this->vertices];
            for (int i = 0; i < this->vertices; i++)
            {
                visited[i] = false;
            }

            queue<int> q;
            q.push(startNode);
            visited[startNode] = true;
            
            while(!q.empty())
            {
                int vertex = q.front();
                cout << vertex << " ";
                q.pop();

                node *cur = Adjlist[vertex];
                while(cur != nullptr)
                {
                    int neighbour = cur->val;
                    if (!visited[neighbour])
                    {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                    cur = cur->next;
                }
            }
        }
        
        void display()
        {
            for (int i = 0; i < this->vertices; i++)
            {
                node *tmp = Adjlist[i];
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

};


int main()
{

    AdjacencyList g(5);

    // Add edges between vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    // Print the adjacency list before deleting edges
    cout << "Adjacency List before deleting edges:" << endl;
    g.display();

    // Delete edge between vertex 0 and 2
    cout << "\nDeleting edge between vertex 0 and 2..." << endl;
    g.deleteEdge(0,2);

    // Print the adjacency list after deletion
    cout << "Final graph:" << endl;
    g.display();

    g.bfs(0);
    cout << endl;
    g.performDFS(0);

    return 0;
}