#include <iostream>
using namespace std;

struct node
{
    int src;
    int dest;
    node *next;

    node(int src, int dest, node *next)
    {
        this->src = src;
        this->dest = dest;
        this->next = next;
    }
};

class EdgeList
{
    node *edges;

public:
    EdgeList()
    {
        edges = nullptr;
    }

    void addEdge(int src, int dest)
    {
        node *newNode = new node(src, dest, edges);
        edges = newNode;
    }

    void DeleteEdge(int src, int dest)
    {
        node *cur = edges, *prev = nullptr;
        while (cur != nullptr && (cur->src != src || cur->dest != dest))
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr)
        {
            cout << "\nThere is no edge between " << src << " and " << dest << endl;
        }
        else
        {
            if (prev == nullptr)
            {
                edges = edges->next;
            }
            else
            {
                prev->next = cur->next;
            }
            delete cur;
        }
    }

    void displayEdges()
    {
        node *cur = edges;
        while (cur != nullptr)
        {
            cout << "(" << cur->src << ", " << cur->dest << ") ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main()
{
    EdgeList graph;

    cout << "Adding edges:\n";
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 1);
    cout << "Edge List after adding edges: ";
    graph.displayEdges();

    cout << "\nDeleting edge (2, 3):\n";
    graph.DeleteEdge(2, 3);
    cout << "Edge List after deleting edge (2, 3): ";
    graph.displayEdges();

    cout << "\nAttempting to delete non-existing edge (2, 5):\n";
    graph.DeleteEdge(2, 5);
    cout << "Edge List after attempting to delete edge (2, 5): ";
    graph.displayEdges();

    cout << "\nDeleting edge (4, 1):\n";
    graph.DeleteEdge(4, 1);
    cout << "Edge List after deleting edge (4, 1): ";
    graph.displayEdges();

    return 0;
}
