#include<bits/stdc++.h>
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
typedef vector< pair<L,L> > Y;
typedef queue < pair<L,L> > Q;
#define limit 32000
#define MAX 1000001
#define MOD 1000000007
#define mod 1000000006
#define pb push_back
#define mp make_pair
#include <unordered_set>


int BFS(unordered_set<int> visited,int n, vector<int>* edges, int start, Q q)
{
	// cout<<start+1<<" "<<endl;
	visited.insert(start);
	int w;
	pair<L,L> node;
	node.first = start;
	node.second = 0;
	int level = 0;
	while(1)
	{
		//cout<<"vertex"<<node.first+1<<endl;
		for (int i = 0; i < edges[start].size(); ++i)
		{
			w = edges[start][i];
			// cout<<"edges"<<w+1<<endl;
			if(visited.count(w) == 0)
			{	
				// cout<<w+1<<" "<<endl;
				node.first = w;
				node.second = level+1;

				q.push(node);
				visited.insert(w);

				if(w+1==n)
					return level+1;
			}
		}
		if(q.empty())
			return -1;

		node = q.front();
		start = node.first;
		level = node.second;
		//cout<<"A"<<node.first+1<<level<<endl;
		q.pop();
		
	}

}
int BFSHelper(int n, vector<int>* edges)
{
	unordered_set<int> visited;
	Q q;
	return BFS(visited,n,edges,0,q);
}
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin >> n;
		int m;
		cin >> m;
	
		vector<int>* edges = new vector<int>[n];
		for (int i = 0; i < m; i++) 
		{
			int j, k;
			cin >> j >> k;
			edges[j - 1].push_back(k - 1);
			edges[k - 1].push_back(j - 1);
		}
		// for (int i = 0; i < m; ++i)
		// {
		// 	cout<<"vertex"<<i+1<<endl;
		// 	for (int j = 0; j < edges[i].size(); ++j)
		// 	{
		// 		cout<<edges[i][j]+1<<" ";
		// 	}
		// 	cout<<endl;
		// }
		cout<<BFSHelper(n,edges)<<endl;
		delete []edges;
	}
	return 0;
}





