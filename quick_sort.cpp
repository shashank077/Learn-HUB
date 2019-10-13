#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
	int z = *a;
	*a = *b;
	*b = z;
}

int partition(int a[],int low,int high)
{
	int pivot = a[high];
	int x = low-1;
	for (int i = low; i < high; ++i)
	{
		if(a[i] <= pivot)
		{
			x++;
			swap(&a[x],&a[i]);
		}
	}
	swap(&a[x+1],&a[high]);
	return x+1;

}


void quick_sort(int a[],int low,int high)
{
	if(low < high)
	{
		int pivot = partition(a,low,high);
		quick_sort(a,pivot+1,high);
		quick_sort(a,low,pivot-1);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	quick_sort(a,0,n-1);	
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}

}