#include<iostream>
using namespace std;

class Queue{
    private:
    struct Node{
        int data;
        struct Node *next;
    }*front,*rear;
    public:
    Queue()
    {
        front=NULL;
        rear=NULL;
    }
    void enqueue(int n);
    void dequeue();
    void peek();


};

void Queue::enqueue(int n)
{
    if(front==NULL && rear==NULL)
    {
        front =rear=new Node();
        front->data=n;
        front->next=NULL;
    }
    
    else{
        struct Node *newnode=new Node();
        newnode->data=n;
        newnode->next=NULL;
        rear->next=newnode;
        rear=newnode;
    }
}

void Queue::dequeue()
{
    if(front==NULL && rear==NULL)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else if(front==rear)
    {
        cout<<"The element dequeued is: "<<front->data<<endl;
        front=NULL;
        rear=NULL;
    }
    else{
        struct Node *temp=front;
        cout<<"The element dequeued is: "<<front->data<<endl;
        front=front->next;
        delete temp;
    }
}

void Queue::peek()
{
    if(front==NULL && rear ==NULL)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else if(front==rear)
    {
        cout<<"Queue is Full"<<endl;
    }
    else{
        cout<<front->data<<endl;
    }
}

int main()
{
    Queue q1;
    while(1)
    {
        cout<<"1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit"<<endl;

        int choice;
        cout<<"Enter the Choice"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            int n;
            cin>>n;
            q1.enqueue(n);
            break;
        case 2:
             q1.dequeue();
             break;
        case 3:
              q1.peek();
              break;
        
        default:
              cout<<"Thank You"<<endl;
              exit(0);
              return 0;
        }        

    }
}