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
    //cout<<i<<" ";
    for(int k=0;k<adj[i].size();k++)
    {
		if (visited[adj[i][k]] == false)
			DFSV(adj[i][k], adj, visited);
    }

}
void print(int c)
{
    cout<<c<<"Connected components"<<endl;
}
void DFSgraph(vector<int> adj[],int v)
{
    int ctr=0;
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++)
    {
        if(visited[i] == false)
            ctr++;
            DFSV(i,adj,visited);
    }
    print(ctr);
}

int main()
{
    int v;
    cin>>v;
    vector<int> adj[v];
    insedge(adj ,0,1);
    insedge(adj ,2,3);   
   // insedge(adj ,4,5);
    DFSgraph(adj,v);
    return 0;
}