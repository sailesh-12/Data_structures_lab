#include <iostream>
using namespace std;

class List
{
private:
    struct Node
    {
        int data;
        struct Node *next;
    } *tail;

public:
    List()
    {
        tail = NULL;
    }
    // Prototype definition
    void insertBegin(int);
    void insertEnd(int);
    void insertPos(int, int);
    void deleteBegin();
    void deleteEnd();
    void deletePos(int);
    void display();
    void search(int);
    int count();
};
void List::search(int data)
{
    struct Node *p = tail->next;
    bool found = false;
    do
    {
        if (p->data == data)
        {
            found = true;
            break;
        }
        p = p->next;
    } while (p != tail->next);
    if (found)
    {
        cout << data << " found\n";
    }
    else
    {
        cout << data << " not found\n";
    }
}
int List::count()
{
    struct Node *p = tail->next;
    int count = 0;
    do
    {
        count++;
        p = p->next;
    } while (p != tail->next);
    cout << "Count :" << count;
    return count;
}
// Inserting a node at the Beginning
void List::insertBegin(int data)
{
    if (tail == NULL)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = temp;
        tail = temp;
    }
    else
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = data;
        newnode->next = tail->next;
        tail->next = newnode;
    }
}
// Inserting a node at the End
void List::insertEnd(int data)
{
    if (tail == NULL)
    {
        insertBegin(data);
    }
    else
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = data;
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}
void List::insertPos(int data, int pos)
{
    if (tail == NULL || pos <= 0)
    {
        insertBegin(data);
    }
    else
    {
        struct Node *p = tail->next;
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = data;
        while (pos != 1)
        {
            p = p->next;
            pos--;
        }
        newnode->next = p->next;
        p->next = newnode;
    }
}
void List::deleteBegin()
{
    if (tail == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    else
    {
        struct Node *temp = tail->next;
        tail->next = temp->next;
        free(temp);
        temp = NULL;
    }
}
void List::deleteEnd()
{
    if (tail == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    else if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
    }
    else
    {
        struct Node *p = tail->next;
        while (p->next->next != tail->next)
        {
            p = p->next;
        }
        struct Node *temp = p->next;
        p->next = tail->next;
        free(temp);
        temp = NULL;
        tail = p;
    }
}
void List::deletePos(int pos)
{
    if (tail == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else if (pos < 0 || pos > count())
    {
        cout << "Invalid Position" << endl;
    }
    else
    {
        struct Node *p = tail->next;
        while (pos != 1)
        {
            p = p->next;
            pos--;
        }
        struct Node *temp = p->next;
        p->next = p->next->next;
        free(temp);
        temp = NULL;
    }
}

int main()
{
    List l;
    while (1)
    {
        int choice, data;
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at a Position\n";
        cout << "4. DeleteBegin\n";
        cout << "5. DeleteEnd\n";
        cout << "6.DeletePosition\n";
        cout << "7.Search\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter the data to be inserted: ";
            cin >> data;
            l.insertBegin(data);
            break;
        case 2:
            cout << "Enter the data to be inserted: ";
            cin >> data;
            l.insertEnd(data);
            break;
        case 3:
            cout << "Enter the data to be inserted: ";
            cin >> data;
            cout << "Enter the position: ";
            int pos;
            cin >> pos;
            break;
        case 4:
            l.deleteBegin();
            break;
        case 5:
            l.deleteEnd();
            break;
        case 6:
            cout << "Enter the position to delete: ";
            int posDelete;
            cin >> posDelete;
            l.deletePos(posDelete);
            break;
        case 7:
            cout<<"Enter a data to be inserted:\n";
            cin>>data;
            l.search(data);
            break;
        case 8:
            l.display();
            return 0;
            break;
        case 9:
           cout<<"Exit\n";
            return 0;
      
        }
    }
}

void List::display()
{

    struct Node *p = tail->next;
    do
    {
        cout << p->data << "->";
        p = p->next;
    } while (p != tail->next);
    cout << tail->next->data;
    cout << endl;
}