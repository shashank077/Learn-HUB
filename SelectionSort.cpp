#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<endl<<"Enter the Size of the array"<<endl;
    cin>>n;
    cout<<"======================================="<<endl;
    cout<<"Enter the elements of the array"<<endl;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int min,temp,position;
    for(int i=0;i<n-1;i++)
    {
        min=arr[i];
        position=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                position=j;
            }
        }
        temp=arr[position];
        arr[position]=arr[i];
        arr[i]=temp;
    }
    cout<<"======================================="<<endl;
    cout<<"Sorted Array is "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}
