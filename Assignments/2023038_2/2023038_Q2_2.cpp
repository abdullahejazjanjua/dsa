#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

class Person
{
    string name;
    string address;
    string phone_number;
    public:
        Person(){}
        Person(string name, string address, string phone_number)
        {
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            this->name = name;
            this->address = address;
            this->phone_number = phone_number;
        }
        void display()
        {
            cout << "Name: " << this->name << endl;
            cout << "Address: " << this->address << endl;
            cout << "Phone Number: " << this->phone_number << endl;
        }
        string getName()
        {
            return this->name;
        }
};

struct node
{
    Person p;
    node *next;
    node(){}
};

class PhoneBook
{
    node *head;
    public:
        PhoneBook()
        {
            head = NULL;
        }
        void display()
        {
            node *cur = head;
            while(cur != NULL)
            {
                cur->p.display();
                cout << endl;
                cur = cur->next; 
            }
        }

        void find(string name)
        {
            node *cur = head;
            while(cur != NULL && cur->p.getName() != name)
            {
                cur = cur->next;
            }
            cur->p.display();
        }

        void add(Person p)
        {
            node *newNode = new node;
            newNode->p = p;
            if (head == NULL)
            {
                newNode->next = head;
                head = newNode;
                return;
            }
            node *cur = head, *prev = NULL;
            while(cur != NULL && p.getName()[0] > cur->p.getName()[0])
            {
                prev = cur;
                cur = cur->next;
            }
            if (cur == head)
            {
                cur->next = newNode;
            }
            else
            {
                prev->next = newNode;
                newNode->next = cur;
            }
        }
};
int main()
{
    PhoneBook pb;
    char q;
    while(true)
    {
        string name, phone_number, address;
        cout << "\nEnter name: ";
        getline(cin, name);
        cout << "\nEnter Address: ";
        getline(cin, address);
        cout << "\nEnter Phone Number: "; 
        getline(cin, phone_number);

        Person P(name, address, phone_number);
        pb.add(P);
        cout << "\nPress q to quit\n";
        cin >> q;
        cin.ignore();
        if (q == 'q')
        {
            break;
        }
    }
    pb.display();
    string name_to_find;
    cout << "\nEnter name to find: ";
    getline(cin, name_to_find);
    pb.find(name_to_find);

    return 0;
}