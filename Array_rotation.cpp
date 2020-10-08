/*--------------------------------
		Anshul Gangwar
	Chandigarh University
--------------------------------*/
#include<bits/stdc++.h>
using namespace std;

#define ll 			long long
#define For(i,n) 	for(int i = 0;i<n;i++)
#define Rfor(i,n) 	for(int i = n-1;i>= 0;i--)
#define v 			vector<int> v

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		For(i,n)
		{
			cin>>a[i];
		}
		int d;
		cin>>d;
		while(d--)
		{
			int z = a[0];
			For(i,n)
			{
				a[i] = a[i+1];
			}
			a[n-1] = z;
		}
		for (int i = 0; i < n; ++i)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
