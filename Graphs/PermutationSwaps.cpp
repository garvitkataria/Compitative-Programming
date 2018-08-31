#include<bits/stdc++.h>
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
typedef vector< pair<L,L> > Y;
#define limit 32000
#define MAX 1000001
#define MOD 1000000007
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
		v P ;
		v Q ;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin>>x;
			P.pb(x);
		}
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin>>x;
			Q.pb(x);
		}
		vector<int>* edges = new vector<int>[n];
		
		for (int i = 0; i < m; i++) {
			int j, k;
			cin >> j >> k;
			edges[j - 1].push_back(k - 1);
			edges[k - 1].push_back(j - 1);
		}

		unordered_set<unordered_set<int>*>* components = getComponents(edges, n);

		//print
		unordered_set<unordered_set<int>*>::iterator it = components->begin();
		int flag=1;
		while (it != components->end()) 
		{
			unordered_set<int>* component = *it;
			
			unordered_set<int>::iterator it2 = component->begin();
			set<int> CheckP;
			set<int> CheckQ;
			while (it2 != component->end()) 
			{
				//cout << *it2 + 1 << " ";
				CheckP.insert(P[*it2 ]);
				CheckQ.insert(Q[*it2 ]);
				it2++;
			}

				set<int>::iterator e1=CheckP.begin();
				set<int>::iterator e2=CheckQ.begin();
				while(e1!=CheckP.end())
				{
					if(*e1 != *e2)
						flag=0;
					e1++;
					e2++;
				}
			delete component;
			it++;
		}
		if(flag)
			printf("YES\n");
		else
			cout<<"NO"<<endl;
		delete components;
		delete [] edges;
		P.clear();
		Q.clear();
	}

}





