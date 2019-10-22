#include <bits/stdc++.h>
#define ll long long
//LearnHUB Exclusive 
//Factors of a no. computed in O(sqrt(n)) Complexity instead of naive O(n)
//Published by Shashank Kumar 
//Github @shashank077
using namespace std;
void fact(ll n)
    {
        vector<ll> sol;
        for(int i=1;i<=sqrt(n);i++)if(!(n%i)){
         sol.push_back(i);
         if(i!=n/i)
         sol.push_back(n/i);
    }
     sort(sol.begin(), sol.end());
     ll x=sol.size();
     for(int i=0;i<x;i++)
     {
      cout<<sol[i]<<" ";
     }
     cout<<endl;
}
int main()
{
    ll T;
    cin>>T;
    while(T--)
    {
        ll n=0;
        cin>>n;
        fact(n);
    }
}


