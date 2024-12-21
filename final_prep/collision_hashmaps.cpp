#include <iostream>
using namespace std;

class hashmap
{
    int *map;
    bool *hasValue;
    int N;
    public:
        hashmap(int N)
        {
            this->N = N;
            map = new int[N];
            hasValue = new bool[N];
            for (int i = 0; i < this->N; i++)
            {
                hasValue[i] = false;
            }
        }

        int hash(int key)
        {
            return key % this->N;
        }

        int hash_02(int key)
        {
            int R = 7;  
            return R - (key % R);  
        }
        void add(int key, bool quad = false, bool double_hashing = false)
        {
            int idx = hash(key);   
            int startIdx = idx;
            int attempt = 1;
            while(true)
            {
                if (!hasValue[idx])
                {
                    hasValue[idx] = true;
                    map[idx] = key;
                    break;
                }
                else
                {

                    if(!quad && !double_hashing)
                    {
                        idx = (idx + 1) % N;
                    }
                    else if (quad)
                    {
                        idx = (startIdx + attempt * attempt) % N;
                    }
                    else 
                    {
                        idx = (idx + attempt * hash_02(key)) % this->N;
                    }
                }
                attempt++;
                if (idx == startIdx)
                {
                    cout << "\nThere is no space in the hashmap\n";
                    break;
                }
                
            }
        }

        void deleteNode(int key, bool quad = false, bool double_hashing = false)
        {
            int idx = hash(key);
            int startIdx = idx;
            int attempt = 1;
            while(true)
            {
                if(map[idx] == key)
                {
                    hasValue[idx] = false;
                    break;
                }
                else
                {
                    if(!quad && !double_hashing)
                    {
                        idx = (idx + 1) % this->N;
                    } 
                    else if (quad)
                    {
                        idx = (startIdx + attempt * attempt) % this->N;
                    }
                    else if (double_hashing)
                    {
                        idx = (idx + attempt * hash_02(key)) % this->N;
                    }
                }
                attempt++;
                if (idx == startIdx)
                {
                    cout << "\nThere is no " << key << " in the hashmap\n";
                    break;
                }
            }
        }

        void display()
        {
            int i = 0;
            cout << "\nCurrent state of the hashmap: \n";
            while(i < N)
            {
                if(hasValue[i])
                {
                    cout << i << " : " << map[i] << endl ;
                }
                else
                {
                    cout << i << ": (empty) \n";
                }
                i++;
            }
        }
};

int main()
{
    cout << "\nTesting Linear Probing:" << endl;
    hashmap h1(10);
    h1.add(5);  
    h1.add(15); 
    h1.add(25); 
    h1.add(35); 
    h1.display(); 

    cout << "\nTesting Quadratic Probing:" << endl;
    hashmap h2(10);
    h2.add(5, true);   
    h2.add(15, true);  
    h2.add(25, true);  
    h2.add(35, true);  
    h2.display();

    cout << "\nTesting Double Hashing:" << endl;
    hashmap h3(10);
    h3.add(5, false, true);   
    h3.add(15, false, true);  
    h3.add(25, false, true);  
    h3.add(35, false, true);  
    h3.display(); 

    cout << "\nTesting Deletion:" << endl;
    hashmap h4(10);
    h4.add(5);   
    h4.add(15);  
    h4.add(25);  
    h4.add(35);  
    h4.deleteNode(5);   
    h4.deleteNode(15);  
    h4.deleteNode(25);  
    h4.deleteNode(35); 
    h4.display(); 

    cout << "\nTesting Deletion of Non-Existent Key:" << endl;
    h4.deleteNode(50);  

    return 0;
}
