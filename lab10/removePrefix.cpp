#include <bits/stdc++.h>
using namespace std;

int hash[1000000];


int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		vector<int> vec(n); 
		
		for (int i = 0; i < n; i++)
		{
			cin >> vec[i];
		}

		for (int i = n-1; i>=0; i--)
		{
			if (hash[vec[i]]==0)
			{
				hash[vec[i]] = 1;
			}else{
				break;
			}
		}
		int count=0;
		for (int i = n-1; i >=0; i--)
		{
			if (hash[vec[i]] == 1)
			{
				hash[vec[i]] = 0;
				count++;
			}
			
		}
		cout<<n-count<<endl;
		
	}
}