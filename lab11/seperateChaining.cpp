#include <iostream>
#include "LinkedList.h"
using namespace std;

class HashTable {
private:
    List* table;
    int size;

public:
    HashTable(int s) {
        size = s;
        table = new List[size];
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int idx = hashFunction(key);
        table[idx].insertBegin(key);
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << i << ": ";
            table[i].display();
        }
    }

    void search(int key) {
        int idx = hashFunction(key);
        cout << "Searching in chain at index " << idx << endl;
        table[idx].search(key);
    }

    void remove(int key) {
        int idx = hashFunction(key);
        List& chain = table[idx];

        int pos = 0;
        List::Node* current = chain.getHead();
        while (current) {
            if (current->data == key) {
                chain.deletePosition(pos);
                cout << "Deleted " << key << " from index " << idx << endl;
                return;
            }
            current = current->next;
            pos++;
        }
        cout << "Key not found in chain." << endl;
    }

    ~HashTable() {
        delete[] table;
    }
};

int main() {
    HashTable ht(5);
    int choice, data;

    while (true) {
        cout << "\n1. Insert\n2. Display\n3. Search\n4. Delete\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            ht.insert(data);
            break;
        case 2:
            ht.display();
            break;
        case 3:
            cout << "Enter data to search: ";
            cin >> data;
            ht.search(data);
            break;
        case 4:
            cout << "Enter data to delete: ";
            cin >> data;
            ht.remove(data);
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}
