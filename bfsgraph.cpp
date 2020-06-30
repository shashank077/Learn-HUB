#include<bits/stdc++.h>
#define ll long long
using namespace std;
void print(int c)
{
	cout<<"connected components="<<c<<endl;
}
void bfs(vector<int>adj[],int src,int n)
{
	vector<int> vis(n,false);
	queue <int> qr;
	int concom=0;
	vis[src]=true;
	qr.push(src);
	while(!qr.empty())
	{
		int p=qr.front();
		cout<<p<<" ";
		qr.pop();
		for(int i=0;i<adj[p].size();i++)
		{
			if(vis[adj[p][i]]==false)
			{
				concom+=1;
				vis[adj[p][i]]=true;
				qr.push(adj[p][i]);
			}
		}
	}
	print(concom);
}
int main()
{
	int t=0;
	cin>>t;
	while(t--)
	{
		int vertex=0,edge=0;
		cin>>vertex>>edge;
		vector <int> adj[vertex+1];
		for(int i=0;i<edge;i++)
		{
			int a=0,b=0;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int source=0;
		cin>>source;
		bfs(adj,source,vertex);
	}
}