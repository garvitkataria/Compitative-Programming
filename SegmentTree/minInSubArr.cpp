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

	tree[treenode] = min(tree[2*treenode] ,tree[2*treenode+1]);
}

void updateTree(int* arr, int* tree, int start, int end, int treenode, int idx, int value)
{
	if(start==end)
	{
		arr[idx] = value;
		tree[treenode] = value;
		return;
	}

	int mid = (start + end)/2 ;

	if(idx > mid)
		updateTree(arr, tree, mid+1, end, 2*treenode+1, idx, value);
	else
		updateTree(arr, tree, start, mid, 2*treenode, idx, value);

	tree[treenode] = min(tree[2*treenode] , tree[2*treenode+1]);
}

int query(int* tree, int start, int end, int treenode, int left, int right)
{
	// Completely outside the given range
	if(start>right || end<left)
		return INT_MAX;

	// Completely inside the given range
	if(start>=left && end<=right)
		return tree[treenode];

	// Partially inside and partially outside
	int mid = (start + end)/2 ;
	int ans1 = query(tree, start, mid, 2*treenode, left, right);
	int ans2 = query(tree, mid+1, end, 2*treenode+1, left, right);

	return min(ans1,ans2);
}

// int main() 
// {
// 	int n = 5;
// 	int arr[] = {1,2,3,4,5};
// 	int * tree = new int [2*n];

// 	buildTree(arr,tree,0,n-1,1); //start = 0; end = 8; starting with index =1;

// 	// for (int i = 1; i < 10; ++i)
// 	// 	cout<<tree[i]<<endl;

// 	updateTree(arr, tree, 0, n-1, 1, 1, 0); // 1 2 10 4 5

// 	for (int i = 1; i < 10; ++i)
// 		cout<<tree[i]<<endl;
	
// 	int ans = query(tree, 0, n-1, 1, 3, 4);
// 	cout<<ans<<endl;
// 	return 0;
// }
int main() 
{
	int arr[100005];
	int N,Q;
	cin>>N>>Q;
	for (int i = 0; i < N; ++i)
	{
		cin>>arr[i];
	}

	int *tree = new int [4*N];

	for (int i = 0; i < 4*N; ++i)
	{
		tree[i]=INT_MAX;
		//cout<<tree[i]<<" ";
	}
	cout<<endl;
	buildTree(arr,tree,0,N-1,1); //start = 0; end = 8; starting with index =1;

	char q;
	int l,r;
	for (int i = 0; i < Q; ++i)
	{
		cin>>q>>l>>r;
		if(q=='q')
		{
			int ans = query(tree, 0, N-1, 1, l-1, r-1);
			cout<<ans<<endl;
		}
		else if(q=='u')
		{
			updateTree(arr, tree, 0, N-1, 1, l-1, r);
		}
		// for (int i = 1; i < 2*N; ++i)
		// 	cout<<tree[i]<<endl;
		// cout<<"_____"<<endl;
	}
	return 0;
}