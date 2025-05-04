#include <bits/stdc++.h>
using namespace std;
#define size 10
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
	return (num % size);
}
void HashTable::insert(int key)
{
	int slot=hashfunction(key);

	if(hashtable[slot]!=-1)
	{
		int i=1;
		while(hashtable[slot+i]!=-1 && i<size)
		{
			i++;
		}
		hashtable[slot+i]=key;
	}else{
		hashtable[slot]=key;
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

void HashTable::del(int key)
{
	int slot=hashfunction(key);
	if(hashtable[slot]==key)
	{
		hashtable[slot]=-1;
	}else{
		int i=1;
		while(hashtable[slot+i]!=key && i<size)
		{
			i++;
		}
		if(hashtable[slot+i]==key)
		{
			cout<<"Deleted element is "<<hashtable[slot+i]<<endl;
			hashtable[slot+i]=-1;
		}
	}
}

void HashTable::search(int key)
{
	int slot=hashfunction(key);
	if(hashtable[slot]==key)
	{
		cout<<"Element is found";
	}else{
		int i=1;
		while(hashtable[slot+i]!=key && i<size)
		{
			i++;
		}
		if(hashtable[slot+i]==key)
		{
			cout<<"Element is found"<<endl;
		}else{
			cout<<"Element is not found"<<endl;
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

