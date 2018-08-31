#include<bits/stdc++.h>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

void dfs(vector<int>* edges, int start, unordered_set<int> &visited, stack<int> &finishStack) {
	visited.insert(start);
	for (int i = 0; i < edges[start].size(); i++) {
		int adjacent = edges[start][i];
		if (visited.count(adjacent) == 0) {
			dfs(edges, adjacent, visited, finishStack);
		}
	}
	finishStack.push(start);
}

void dfs2(vector<int>* edges, int start, unordered_set<int>* component, unordered_set<int> & visited) {
	visited.insert(start);
	component->insert(start);
	for (int i = 0; i < edges[start].size(); i++) {
		int adjacent = edges[start][i];
		if (visited.count(adjacent) == 0) {
			dfs2(edges, adjacent, component, visited);
		}
	}
}
void Prnt(unordered_set<int>* component)
{
	int *A;
	int n=component->size();
	A = new int[n]; 
	int i = 0;

	unordered_set<int>::iterator it;
	it = component->begin();
	while(it!=component->end())
	{
		A[i]=*it+1;
		it++;
		i++;
	}
	sort(A,A+n);
		for (int i = 0; i < n; ++i)
		{
			cout<<A[i]<<" ";
		}
	
	cout<<endl;
}
unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges, vector<int>* edgesT, int n) {
	unordered_set<int> visited;
	stack<int> finishedVertices;
	for (int i = 0; i < n; i++) {
		if (visited.count(i) == 0) {
			dfs(edges, i, visited, finishedVertices);
		}
	}
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	visited.clear();
	while (finishedVertices.size() != 0) {
		int element = finishedVertices.top();
		finishedVertices.pop();
		if (visited.count(element) != 0) {
			continue;
		}
		unordered_set<int>* component = new unordered_set<int>();
		dfs2(edgesT, element, component, visited);
		output->insert(component);
	}
	return output;
}

int main() {
	int n;
	cin >> n;
	vector<int>* edges = new vector<int>[n];
	vector<int>* edgesT = new vector<int>[n];
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int j, k;
		cin >> j >> k;
		edges[j - 1].push_back(k - 1);
		edgesT[k - 1].push_back(j - 1);
	}
	unordered_set<unordered_set<int>*>* components = getSCC(edges, edgesT, n);
	unordered_set<unordered_set<int>*>::iterator it = components->begin();
	while (it != components->end()) 
	{
		unordered_set<int>* component = *it;
		if(component->size()==1 && edges[*component->begin()].size()==0)
		{
			cout<<"0"<<endl;
			return 0;
		}
		unordered_set<int>::iterator it2 = component->begin();
		int flag=1;
		while (it2 != component->end()) 
		{
			for (int i = 0; i < edges[*it2].size(); ++i)
			{
				if(component->count(edges[*it2][i])!=1 )
				{
					flag=0;
				}
			}
			//cout << *it2  + 1<< " ";
			it2++;

		}
		if(flag==1)
		{
			cout<<component->size()<<endl;
			Prnt(component);
			delete components;
			delete [] edges;
			delete [] edgesT;
			return 0;
		}

		delete component;
		it++;
	}
	delete components;
	delete [] edges;
	delete [] edgesT;
	return 0;
}
