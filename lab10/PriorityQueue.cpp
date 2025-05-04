#include<iostream>
using namespace std;

class PriorityQueue{
    private:
       int arr[6];
       int curr;
    public: 
       PriorityQueue()
       {
         curr=-1;
       }

    void insert(int value);
    void heapifyUp(int index);
    void deleteNode();
    void heapifyDown(int index);
    void display();
    void search(int n);
    void heapSort();
    
};

void PriorityQueue::insert(int value){
    curr++;
    arr[curr]=value;
    heapifyUp(curr);
}

void PriorityQueue::heapifyUp(int index)
{
    int parent=(index-1)/2;
    while(index>0)
    {
        if(arr[parent]>arr[index])
        {
            int temp=arr[parent];
            arr[parent]=arr[index];
            arr[index]=temp;
            index=parent;
            parent=(index-1)/2;
        }else{
            break;
        }
    }
}

void PriorityQueue::deleteNode()
{
    if(curr==-1){
        cout<<"Queue is empty"<<endl;
        return;
    }else{
        cout<<"Deleted element is "<<arr[0]<<endl;
        arr[0]=arr[curr];
        curr--;
        heapifyDown(0);
    }
    
}
void PriorityQueue::heapifyDown(int index)
{
    int left=2*index+1;
    int right=2*index+2;
    int minIndex=index;
    if(left<=curr && arr[left]<arr[minIndex])
    {
        minIndex=left;
    }
    if(right<=curr && arr[right]<arr[minIndex])
    {
        minIndex=right;
    }
    if(minIndex!=index)
    {
        int temp=arr[index];
        arr[index]=arr[minIndex];
        arr[minIndex]=temp;
        heapifyDown(minIndex);
    }
}

void PriorityQueue::heapSort()
{
    if (curr == -1) {
        cout << "Heap is empty" << endl;
        return;
    }

    int temp[6];
    int originalCurr = curr;
    int tempSize = 0;

    // Repeatedly delete the root and store it in temp[]
    while (curr >= 0) {
        temp[tempSize++] = arr[0];
        arr[0] = arr[curr];
        curr--;
        heapifyDown(0);
    }

    for (int i = 0; i <= originalCurr; i++) {
        arr[i] = temp[i];
    }
    curr = originalCurr;

    cout << "Sorted elements: ";
    for (int i = 0; i < tempSize; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
}

void PriorityQueue::search(int n)
{
    for(int i=0;i<=curr;i++)
    {
        if(arr[i]==n)
        {
            cout<<"Element found"<<endl;
            return;
        }
    }
    cout<<"Element not found"<<endl;
}

void PriorityQueue::display()
{
    for(int i=0;i<=curr;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    PriorityQueue p1;

    while(true)
    {
        int choice;
        cout<<"1.Insert\n2.Delete\n3.Display\n4.Search"<<endl;
        cout<<"Enter the choice"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                int value;
                cout<<"Enter the value"<<endl;
                cin>>value;
                p1.insert(value);
                break;
         
            case 2:
                p1.deleteNode();
                break;
            case 3:
                p1.display();
                break;
            case 4:
                 int n;
                 cout<<"Enter the value to be searched"<<endl;
                 cin>>n;
                 p1.search(n);
                 break;
            case 5:
                p1.heapSort();
                break;
            default:
                cout<<"Invalid Choice"<<endl;
                exit(0);
        }
    }
}
