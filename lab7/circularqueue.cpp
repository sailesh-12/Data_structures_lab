#include<iostream>
using namespace std;

class Queue{
    private:
    int arr[5];
    int front,rear;
    public:
        Queue()
        {
            front=-1;
            rear=-1;
        }
        void enqueue(int n);
        void dequeue();
        void peek();
};

void Queue::enqueue(int n)
{
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        arr[front]=n;
    }
    else if(front==(rear+1)%5)
    {
        cout<<"Queue is Full"<<endl;
    }else{
        rear=(rear+1)%5;
        arr[rear]=n;
    }
}
void Queue::dequeue()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is Empty"<<endl;
    }else if(front==rear)
    {
        cout<<arr[front]<<endl;
        front=-1;
        rear=-1;
    }
    else{
        cout<<"the element dequeued is:"<<arr[front]<<endl;
        front=(front+1)%5;
    }
}
void Queue::peek()
{
    if(front==-1 && rear ==-1)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else{
        cout<<arr[front]<<endl;
    }

}
int main()
{
    Queue q1;
    while(true)
    {
        cout<<"1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit"<<endl;
        int choice,n;
        cout<<"Enter a Choice:"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter a number"<<endl;
                cin>>n;
                q1.enqueue(n);
                break;
            case 2:
                q1.dequeue();
                break;
            case 3:
                q1.peek();
                break;
            case 4:
                cout<<"Thank You"<<endl;
                exit(0);
        }

    }
}
