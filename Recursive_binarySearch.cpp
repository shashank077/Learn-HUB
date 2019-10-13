#include<bits/stdc++.h>
using namespace std;

string binary_search(int a[],int low,int high,int k)
{
	if(low > high)
		return "Not Found";
	else
	{
		int mid = (low + high) / 2;
		if(a[mid] == k)
			return "Found";
		else if(a[mid] > k)
			return binary_search(a,low,mid-1,k);  
		else
			return binary_search(a,mid+1,high,k);
	}
}


int main()
{
	int a[5] = {1,2,3,4,5};
	cout<<binary_search(a,0,4,4);
}
