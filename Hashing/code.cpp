#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable 
{
    private:
        int table[TABLE_SIZE];
        int collisionCount[TABLE_SIZE];

    public:
        HashTable() 
        {
            for (int i = 0; i < TABLE_SIZE; i++) 
            {
                table[i] = -1;
                collisionCount[i] = 0;
            }
        }

        int hashFunction(int key) 
        {
            return key % TABLE_SIZE;
        }

        void insert(int key) 
        {
            int index = hashFunction(key);
            int probes = 1;
            while (table[index] != -1) 
            {
                index = (index + 1) % TABLE_SIZE; 
                probes++;
            }
            table[index] = key;
            collisionCount[index] = probes;
        }

    void display() 
    {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) 
        {
            cout << "[" << i << "]: ";
            if (table[i] != -1)
                cout << table[i] << " (probe: " << collisionCount[i] << ")";
            else
                cout << -1;
            cout << endl;
        }
    }

};

int main() {
    HashTable ht;

    int numKeys;
    cout << "Enter the number of keys: ";
    cin >> numKeys;

    cout << "Enter the keys: ";
    for (int i = 0; i < numKeys; i++) 
    {
        int key;
        cin >> key;
        ht.insert(key);
    }

    ht.display();

    return 0;
}