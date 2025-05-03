#include<iostream>
#define N 5
using namespace std;

class List{
	private:
	int arr[N];
	int top;
	public:
	List()
	{
		top=-1;
	}
	void push(int);
	void pop();
	void display();
	void peek();
};

void List::push(int n)
{
	if(top==N-1)
	{
		cout<<"Overflow"<<endl;
	}else{
		top++;
		arr[top]=n;
	}
}
void List::peek(){
	if(top==-1){
		cout<<"Underflow"<<endl;
	}else{
		cout<<"Top element is: "<<arr[top]<<endl;
	}
}
void List::pop()
{
	if(top==-1){
		cout<<"Underflow"<<endl;
	}else{
		top--;
	}
}
void List::display()
{
	if(top==-1){
		cout<<"Underflow"<<endl;
	}else{
		for(int i=top;i>=0;i--)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	List l;

	while (true)
	{
		int choice;
		cout<<"1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				int n;
				cout<<"Enter the number"<<endl;
				cin>>n;
				l.push(n);
				break;
			case 2:
				l.pop();
				break;
			case 3:
				l.display();
				break;
			case 4:
				l.peek();
				break;
			case 5:
				exit(0);
		}
	}
	
}