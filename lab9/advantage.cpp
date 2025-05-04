#include <bits/stdc++.h>
using namespace std;

int main()
{
	/*
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<long long int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				long long max1=*max_element(arr.begin()+1,arr.end());
				cout<<arr[i]-max1<<" ";
			}else if(i==n-1)
			{
				long long max1=*max_element(arr.begin(),arr.end()-1);
				cout<<arr[i]-max1<<" ";
			}
			else{
				long long max1=*max_element(arr.begin(),arr.begin()+i);
				long long  max2=max(max1,*max_element(arr.begin()+i+1,arr.end()));
				cout<<arr[i]-max2<<" ";
			}
		}
	} */
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		vector<long long> s(n);

		for (int i = 0; i < n; i++)
			cin >> s[i];

		// Step 1: Find max1 (largest) and max2 (second largest)
		long long max1 = LLONG_MIN, max2 = LLONG_MIN;

		for (int i = 0; i < n; i++)
		{
			if (s[i] > max1)
			{
				max2 = max1;
				max1 = s[i];
			}
			else if (s[i] > max2)
			{
				max2 = s[i];
			}
		}

		// Step 2: Compute the required differences
		for (int i = 0; i < n; i++)
		{
			if (s[i] == max1)
				cout << s[i] - max2 << " ";
			else
				cout << s[i] - max1 << " ";
		}
		cout << "\n";
	}
}