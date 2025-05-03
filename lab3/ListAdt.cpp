#include<iostream>

using namespace std;

class List{
    private:
    int curr;
    int arr[5];
    
    public:
    List(){
        curr=-1;
    }
     
     void insertBegin(int );//prototype
     void insertEnd(int );//prototype
     void insertPos(int,int );//prototype
    void deleteBegin();//prototype
    void deleteEnd();//prototype
    void deletePos(int);//prototype
    void search(int);//prototype
    void Display();//prototype
    void rotate(int ,int);//prototype

    

};
int main()
{
    List l1;

    while(1)
    {
        int n,pos,k;
        int ch;
        cout<<"--------------------------------------------------------------"<<endl;
        cout<<"1.Insert at begin\n2.Insert at end\n3.Insert at position\n4.Delete at begin\n5.Delete at end\n6.Delete at position\n7.Search\n8.Display\n9.Rotate\n10.Exit\n";
        cout<<"Enter a choice as per your requirement:"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                   
                   cout<<"Enter the element to be inserted in the array:\n";
                   cin>>n;
                   l1.insertBegin(n);
                  break;
            case 2:
                   
                   cout<<"Enter the element to be inserted in the array:\n";
                   cin>>n;
                   l1.insertEnd(n);
                   break;
            case 3:
                 cout<<"Enter the element to be inserted in the array:\n";
                 cin>>n;
                 cout<<"Enter position to be inserted:\n";
                 cin>>pos;
                 l1.insertPos(n,pos);
                 break;
            case 4:
                 l1.deleteBegin();
                 break;
            case 5:
                 l1.deleteEnd();
                 break;
            case 6:
                cout<<"Enter position to be deleted:\n";
                cin>>pos;
                l1.deletePos(pos);
                break;
            case 7:
                 cout<<"Enter element to be searched:\n";
                 cin>>n;
                 l1.search(n);
                 break;
            case 8:
                  l1.Display();
                  break;
            case 9:
                 cout<<"Enter the length of the array:\n";
                 cin>>n;
                 cout<<"Enter k value:"<<endl;
                 cin>>k;
                 l1.rotate(n,k);
                 break;
            default:
               cout<<"Thank you";
               exit(1);
               break;
                
        }
    }
    return 0;
}

void List::insertBegin(int n)
{
   
    int temp=curr;
    temp=temp+1;

    if(curr==5)
    {
        cout<<"Array is Full"<<endl;
    }
    while(temp!=0)
    {
        arr[temp]=arr[temp-1];
        temp-=1;

    }
    arr[temp]=n;
    curr++;        
}
void List::insertEnd(int n)
{
    arr[curr+1]=n;
    curr++;
}
void List::insertPos(int n,int pos)
{
    if(pos>curr)
    {
        arr[pos]=n;
        curr++;
    }
    else{
        int temp=curr;
        temp++;
        while(temp>pos)
        {
            arr[temp]=arr[temp-1];
            temp--;
        }
        arr[temp]=n;
        curr++;
    }
}
void List::deleteBegin()
{
    if(curr==-1)
    {
        cout<<"List is empty"<<endl;
    }else{
        int temp=1;
        while(temp<=curr)
        {
            arr[temp-1]=arr[temp];
            temp=temp+1;
        }
        curr--;
    }

}
void List::deleteEnd(){
    if(curr==-1)
    {
        cout<<"List is empty"<<endl;
    }else{
        curr--;
    }
}
void List::deletePos(int pos){
    if(curr==-1)
    {
        cout<<"List is empty"<<endl;
    }else if(pos>curr){
        cout<<"Invalid position"<<endl;
    }
    else{
        int temp=pos+1;
        while(temp<=curr)
        {
            arr[temp-1]=arr[temp];
            temp=temp+1;
        }
        curr--;
    }
}
void List::search(int n){

}
void List::Display(){
    cout<<"Displaying the elements"<<endl;
    if(curr==-1)
    {
        cout<<"List is empty"<<endl;
    }
    for(int i=0;i<=curr;i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<"Current value:"<<curr<<endl;
}
void reverse(int arr[],int start,int end){
    while(start<=end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
void List::rotate(int n, int k){
    if(k>n)
    {
        k=k%n;
    }
    reverse(arr,0,n-k-1);
    reverse(arr,n-k,n-1);
    reverse(arr,0,n-1);
}