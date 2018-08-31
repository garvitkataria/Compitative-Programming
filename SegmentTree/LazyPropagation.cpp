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

void buildTree(int* arr, int* tree, int start, int end, int treenode)
{
	if(start==end)
	{
		tree[treenode] = arr[start];
		return;
	}
	int mid = (start + end)/2 ;

	buildTree(arr, tree, start, mid, 2*treenode);
	buildTree(arr, tree, mid+1, end, 2*treenode+1);

	tree[treenode] = min(tree[2*treenode] , tree[2*treenode+1]);
}
int queryLazy(int* tree, int*lazy, int start, int end, int treenode, int left, int right)
{
	if(lazy[treenode] != 0)
	{
		tree[treenode] += lazy[treenode];
		if(start!=end)
		{
			lazy[2*treenode] += lazy[treenode];
			lazy[2*treenode+1] += lazy[treenode];
		}
		lazy[treenode]=0;
	}

	// Completely outside the given range
	if(start>right || end<left)
		return INT_MAX;

	// Completely inside the given range
	if(start>=left && end<=right)
		return tree[treenode];

	// Partially inside and partially outside
	int mid = (start + end)/2 ;
	int ans1 = queryLazy(tree, lazy, start, mid, 2*treenode, left, right);
	int ans2 = queryLazy(tree, lazy, mid+1, end, 2*treenode+1, left, right);

	return min(ans1,ans2);
}

void updateTreeLazy(int* tree, int* lazy, int low, int high, int startR, int endR, int currPos, int value)
{
	if(low>high)
		return;
	if(lazy[currPos] != 0)
	{
		tree[currPos] += lazy[currPos];
		if(low!=high)
		{
			lazy[2*currPos] += lazy[currPos];
			lazy[2*currPos+1] += lazy[currPos];
		}
		lazy[currPos]=0;
	}

	//NO OVERLAP
	if(startR>high || endR<low)
		return;

	//COMPLETE OVERLAP
	if(startR<=low && endR>=high)
	{
		tree[currPos] += value;
		if(low!=high)
		{
			lazy[2*currPos] += value;
			lazy[2*currPos+1] += value;
		}
		return;
	}

	//PARTIAL OVERLAP
	int mid = (high+low)/2;
	updateTreeLazy(tree, lazy, low, mid, startR, endR, 2*currPos, value);
	updateTreeLazy(tree, lazy, mid+1, high, startR, endR, 2*currPos+1, value);
	tree[currPos] = min(tree[2*currPos],tree[2*currPos+1]);
}


int main() 
{
	int n = 4;
	int arr[] = {1,3,-2,4};
	int * tree = new int [4*n]();

	buildTree(arr,tree,0,n-1,1); //start = 0; end = 8; starting with index =1;

	int * lazy = new int [4*n]();

	cout<<"Segment Tree :-";
	for (int i = 1; i < 4*n; ++i)
		cout<<tree[i]<<" ";
	cout<<endl;
	cout<<"Lazy Tree :-";
	for (int i = 1; i < 4*n; ++i)
		cout<<lazy[i]<<" ";
	cout<<endl;

	//Lazy Update [0,3]->3
	updateTreeLazy(tree, lazy, 0, n-1, 0, 3, 1, 3); //tree, lazy, low, high, startR, endR, currPos, value  

	//Lazy Update [0,1]->2
	updateTreeLazy(tree, lazy, 0, n-1, 0, 1, 1, 2); //tree, lazy, low, high, startR, endR, currPos, value 
	cout<<"Segment Tree :-";
	for (int i = 1; i < 4*n; ++i)
		cout<<tree[i]<<" ";
	cout<<endl;
	cout<<"Lazy Tree :-";
	for (int i = 1; i < 4*n; ++i)
		cout<<lazy[i]<<" ";
	cout<<endl;

	//Querry [1,2]
	queryLazy(tree, lazy, 0, n-1, 1, 1, 2);// tree, lazy, start, end, treenode, left, right
	cout<<"Segment Tree :-";
	for (int i = 1; i < 4*n; ++i)
		cout<<tree[i]<<" ";
	cout<<endl;
	cout<<"Lazy Tree :-";
	for (int i = 1; i < 4*n; ++i)
		cout<<lazy[i]<<" ";
	cout<<endl;


	// updateTree(arr, tree, 0, n-1, 1, 2, 10); // 1 2 10 4 5

	// for (int i = 1; i < 10; ++i)
	// 	cout<<tree[i]<<endl;
	
	// int ans = query(tree, 0, n-1, 1, 2, 4);
	// cout<<ans<<endl;
	return 0;
}
