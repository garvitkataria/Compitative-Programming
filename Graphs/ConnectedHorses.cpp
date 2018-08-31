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
#define M 1000000007
#define mod 1000000006
#define pb push_back
#define mp make_pair
#include <unordered_set>

void dfs(int start, vector<int>* edges, int n, unordered_set<int>& visited, unordered_set<int>* component) 
{
	visited.insert(start);
	component->insert(start);
	for (int i = 0; i < edges[start].size(); ++i)
	{
		int v = edges[start][i];
		if (visited.count(v) == 0) 
		{
			dfs(v, edges,n, visited, component);
		}
		
	}
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n) 
{
	unordered_set<int> visited;
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	for (int i = 0; i < n; i++) 
	{
		if (visited.count(i) == 0) 
		{
			unordered_set<int> * component = new unordered_set<int>();
			dfs(i, edges,n, visited, component);
			output->insert(component);
		}
	}
	return output;
}
L factorial(int a)
{
	L x=1;
	for (int i = 1; i <= a; ++i)
	{
		x*=i;
      x%=M;
	}
	return x;
}
/*
vertex notation
1 2 3 4
5 6 7 8
9 10 11 12

7/4=1
7%4=3
(1,3)
*/
int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m,q,N;
		cin >> n;
		cin >> m;
		cin >> q;

		N=n*m;
		vector<int>* edges = new vector<int>[N+1];

		int *House = new int[N+1];
		for (int i = 0; i < N; ++i)
			House[i]=0;

		for (int i = 0; i < q; i++) 
		{
			int j, k;
			cin >> j >> k;
			j=j-1;
			k=k-1;
			int currentH = j*m+k;
			// cout<<"currentH"<<currentH<<endl;
			int tempH;
			House[currentH] = 1;
			//down
			
			if(j>=2 && k<=m-2)
			{
				int tempH = m*(j-2) + (k+1) ; 
				if( House[tempH] )
				{
					edges[currentH ].push_back(tempH );
					edges[tempH ].push_back(currentH );
				}
				// cout<<currentH<<" "<<tempH<<endl;
			}
			
			if(j>=2 && k>=1)
			{
				tempH = m*(j-2) + (k-1) ; 
				if( House[tempH] )
				{
					edges[currentH ].push_back(tempH );
					edges[tempH ].push_back(currentH );
				}
				// cout<<currentH<<" "<<tempH<<endl;
			}

			//Up
			if(j<=n-3 && k<=m-2)
			{
				tempH = m*(j+2) + (k+1) ; 
				if( House[tempH] )
				{
					edges[currentH ].push_back(tempH );
					edges[tempH ].push_back(currentH );
				}
				// cout<<currentH<<" "<<tempH<<endl;
			}
			if(j<=n-3 && k>=1)
			{
				tempH = m*(j+2) + (k-1) ; 
				if( House[tempH] )
				{
					edges[currentH ].push_back(tempH );
					edges[tempH ].push_back(currentH );
				}
				// cout<<currentH<<" "<<tempH<<endl;
			}
			//right
			if(j<=n-2 && k<=m-3)
			{
				tempH = m*(j+1) + (k+2) ; 
				if( House[tempH] )
				{
					edges[currentH ].push_back(tempH );
					edges[tempH ].push_back(currentH );
				}
				// cout<<currentH<<" "<<tempH<<endl;
			}
			if(j>=1 && k<=m-3)
			{
				tempH = m*(j-1) + (k+2) ; 
				if( House[tempH] )
				{
					edges[currentH ].push_back(tempH );
					edges[tempH ].push_back(currentH );
				}
				// cout<<currentH<<" "<<tempH<<endl;
			}
			//left
			if(j<=n-2 && k>=2)
			{
				tempH = m*(j+1) + (k-2) ; 
				if( House[tempH] )
				{
					edges[currentH ].push_back(tempH );
					edges[tempH ].push_back(currentH );
				}
				// cout<<currentH<<" "<<tempH<<endl;
			}
			if(j>=1&&k>=2)
			{
				tempH = m*(j-1) + (k-2) ; 
				if( House[tempH] )
				{
					edges[currentH ].push_back(tempH );
					edges[tempH ].push_back(currentH );
				}
				// cout<<currentH<<" "<<tempH<<endl;
			}

			// for (int i = 0; i < N; ++i)
			// {
			// 	 cout<<"vertex"<<i+1<<endl;
			// 	for (int j = 0; j < edges[i].size(); ++j)
			// 	{
			// 		cout<<edges[i][j]+1<<" ";
			// 	}
			// 	 cout<<endl;
			// }
		}
		
		unordered_set<unordered_set<int>*>* components = getComponents(edges, N);
		//print
		L ans=0;
		unordered_set<unordered_set<int>*>::iterator it = components->begin();
		while (it != components->end()) 
		{
			unordered_set<int>* component = *it;
			// cout<<component->size()<<endl;
			int yt=component->size();
			if(yt>1)
				ans+=factorial(component->size());
          ans%=M;

			delete component;
			it++;
		}
		delete components;
		delete [] edges;
		if(q==0)
			cout<<0<<endl;
		else if(q>0 && !ans)
			cout<<1<<endl;
		else
			cout<<ans<<endl;
	}
	
}





