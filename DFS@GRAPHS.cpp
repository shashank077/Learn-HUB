#include <bits/stdc++.h>
using namespace std;
void insedge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void DFSV(int i,vector<int> adj[],vector<bool> &visited)
{
    visited[i]= true;
    cout<<i<<" ";
    for(int k=0;k<adj[i].size();k++)
    {
		if (visited[adj[i][k]] == false)
			DFSV(adj[i][k], adj, visited);
    }

}
void DFSgraph(vector<int> adj[],int v)
{
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++)
    {
        if(visited[i] == false)
            DFSV(i,adj,visited);
    }
}

int main()
{
    int v;
    cin>>v;
    vector<int> adj[v];
    insedge(adj,0,1);
    insedge(adj,0,4);
    insedge(adj,1,2);
    insedge(adj,1,3);
    insedge(adj,1,4);
    insedge(adj,2,3);
    insedge(adj,3,4);
    DFSgraph(adj,v);
    return 0;
}
