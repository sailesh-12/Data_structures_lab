#include<iostream>
#include<string>
#include "Trees.h"
using namespace std;

string GetPostfix(string s){
	cout<<"Enter the Postfix Expression\n";
	cin>>s;
	return s;
}




int main()
{
	
	Tree t;
	while(1)
	{
		cout<<"\n1.PostFix Expression\n2.Construct Tree\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exit\nEnter your choice\n";

		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1:
				t.expression=GetPostfix(t.expression);
				break;
			case 2:
				t.constructExpressionTree(t.expression);
				break;
			case 3:
				t.inorderdisplay(t.root);
				break;
			case 4:
				t.preorderdisplay(t.root);
				break;
			case 5:
				t.postorderdisplay(t.root);
				break;
			case 6:
				exit(0);
		}
	}
}

