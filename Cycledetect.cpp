#include <bits/stdc++.h>
#define ll long long
using namespace std;
//To detect cycle in a directed graph.
//use of dfs like approach to explore adjacent vertices in graph
//maintain a visiting array for every vertex we start to explore
//mark the vertex as we visit it in the graph
//if find a (any) vertex which already marked true then it is cyclic
//already marked true case:Meaning is simple,if vertex is already true we have reached or visited same point again thereby discovering a cycle....<3
bool cyclecheck(vector <int> adj[],vector <bool> vis,int curr)
{
	if(vis[curr]==true)
	{
		return true;
	}
	vis[curr]=true;
	bool f=false;
	for(int i=0;i<adj[curr].size();i++)
	{
		f=cyclecheck(adj,vis,adj[curr][i]);
		if(f==true)
		{
			return true;
		}	
	}
	return false;
}
bool cycle(int v,vector<int> adj[])
{
	vector <bool> vis(v,false);
	bool f=false;
	for(int i=0;i<v;i++)
	{
		vis[i]=true;
		for(int j=0;j<adj[i].size();j++)
		{
			f=cyclecheck(adj,vis,adj[i][j]);//explore adjacent vertices//like bfs
			if(f==true)
			{
				return true;
			}
			vis [i]=false;
		}
	}
	return false;
}

int main()//driver
{
	int T=0;
	cin>>T;
	while(T--)
	{
		int v=0,ed=0;
		cin>>v>>ed;// v=number of vertices ed=no. of edges
		vector<int> adj[v];
		for(int i=0;i<ed;i++)
		{
			int a=0;
			int b=0;
			cin>>a>>b;
		/*edge from a to be*/
		adj[a].push_back(b);//maybe adj[v].push_back(u) for undirected
		}
		bool x=cycle(v,adj);
		if(x==true)
		{
			cout<<"Cycle exists"<<endl;
		}
		else
		{
			cout<<"NO Cycle"<<endl;
		}
	}
}