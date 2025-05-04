#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	stack<char> stack;
	string s;
	string ans="";
	getline(cin,s);
	int flag=0;
	for(int i=0;i<s.length();i++)
	{
		stack.push(s[i]);
	}

	while(!stack.empty())
	{
		if((isalpha(stack.top()) || isdigit(stack.top())) && flag==0)
		{
			ans=ans+stack.top();
			stack.pop();

		}
		else if(stack.top()=='+')
		{
			flag+=1;
			stack.pop();
		}
		else{
			while(!stack.empty() && flag>0)
			{
				flag--;
				stack.pop();
			}
		}
	}
	reverse(ans.begin(),ans.end());

	cout<<ans<<endl;



	
}