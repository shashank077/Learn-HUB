#include<bits\stdc++.h>
#define ll long long
using namespace std;
struct queueEntry
{
	int v;
	int d;
};
int minmove(int N,int moves[])
{
	bool *visited=new bool[N];
	for(int i=0;i<N;i++)
	{
		visited[i]=false;
	}
	queue<queueEntry> q;
	visited[0]=true;
	queueEntry s={0,0};
	q.push(s);
	queueEntry qe;
	while(!q.empty())
	{
		qe=q.front();
		int v=qe.v;
		if(v==N-1)
		{
			break;
		}
		q.pop();
		for(int j=v+1;j<=(v+6)&& j<N;j++)
		{
			if(visited[j]==false)
			{
				queueEntry a;
				a.d=(qe.d+1);
				visited[j]=true;
				if(moves[j]!=-1)
				{
					a.v=moves[j];
				}
				else 
					a.v=j;
				q.push(a);
			}
		}
	}
	return qe.d;
}
int main()
{
	int n=30;
	int moves[30];
	memset(moves,-1,sizeof(moves));
	//LADDERS
	moves[2]=21;
	moves[4]=7;
	moves[10]=25;
	moves[19]=28;
	//SNAKES
	moves[26]=0;
	moves[20]=8;
	moves[16]=3;
	moves[18]=6;
	int x=minmove(n,moves);
	cout<<"minmoves of dice="<<x<<endl;
}