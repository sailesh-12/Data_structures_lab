#include<iostream>
#include<math.h>
using namespace std;
#define size 5

class HashTable
{
	private:
	int hashtable[size];
	public:
	HashTable()
	{
		for (int i = 0; i < size; i++)
		{
			hashtable[i] = -1;
		}
	}
	int hashfunction(int num);
	void insert(int key);
	void display();
	void search(int key);
	void del(int key);
};

int HashTable::hashfunction(int num)
{
	return num % size;
}

void HashTable::insert(int key)
{
	int slot=hashfunction(key);
	if(hashtable[slot]==-1)
	{
		hashtable[slot]=key;
	}else{
		int i=1;
		while(hashtable[slot+(int)pow(i,2)]!=-1 && i<size)
		{
			i++;
		}
		if(hashtable[slot+(int)pow(i,2)]==-1)
		{
			hashtable[slot+(int)pow(i,2)]=key;
		}else{
			cout<<"Hash table is full"<<endl;
		}
	}
}

void HashTable::display()
{
	for(int i=0;i<size;i++)
	{
		cout<<hashtable[i]<<" ";
	}
	cout<<endl;
}

void HashTable::search(int key)
{
	int slot=hashfunction(key);
	if(hashtable[slot]==key)
	{
		cout<<"Element is found";
	}else{
		int i=1;
		while(hashtable[slot+(int)pow(i,2)]!=key && i<size)
		{
			i++;
		}
		if(hashtable[slot+(int)pow(i,2)]==key)
		{
			cout<<"Element is found"<<endl;
		}else{
			cout<<"Element is not found"<<endl;
		}
	}
}

void HashTable::del(int key)
{
	int slot=hashfunction(key);
	if(hashtable[slot]==key)
	{
		hashtable[slot]=-1;
	}else{
		int i=1;
		while(hashtable[slot+(int)pow(i,2)]!=key && i<size)
		{
			i++;
		}
		if(hashtable[slot+(int)pow(i,2)]==key)
		{
			cout<<"Deleted element is "<<hashtable[slot+(int)pow(i,2)]<<endl;
			hashtable[slot+(int)pow(i,2)]=-1;
		}
	}
}

int main()
{
	HashTable h1;
	while(true)
	{
		cout<<"1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n";
		cout<<"Enter your choice:";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the number:";
				int num;
				cin>>num;
				h1.insert(num);
				break;
			case 2:
				cout<<"Enter the number to be deleted:";
				cin>>num;
				h1.del(num);
				break;
			case 3:
				cout<<"Enter the number to be searched:";
				cin>>num;
				h1.search(num);
				break;
			case 4:
				h1.display();
				break;
			case 5:
				exit(0);
		}
	}
}