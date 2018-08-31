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

struct node
{
	int maximum;
	int smaximum;
};

void buildTree(int* arr, node* tree, int start, int end, int treenode)
{
	if(start==end)
	{
		tree[treenode].maximum = arr[start];
		tree[treenode].smaximum = INT_MIN;
		return;
	}
	int mid = (start + end)/2 ;

	buildTree(arr, tree, start, mid, 2*treenode);
	buildTree(arr, tree, mid+1, end, 2*treenode+1);
	node left = tree[2*treenode];
	node right = tree[2*treenode+1];

	tree[treenode].maximum = max(left.maximum , right.maximum);
	tree[treenode].smaximum = min(max(left.smaximum , right.maximum),max(left.maximum , right.smaximum));
}

void updateTree(int* arr, node* tree, int start, int end, int treenode, int idx, int value)
{
	if(start==end)
	{
		arr[idx] = value;
		tree[treenode].maximum = value;
		tree[treenode].smaximum = INT_MIN;
		return;
	}

	int mid = (start + end)/2 ;

	if(idx > mid)
		updateTree(arr, tree, mid+1, end, 2*treenode+1, idx, value);
	else
		updateTree(arr, tree, start, mid, 2*treenode, idx, value);

	node left = tree[2*treenode];
	node right = tree[2*treenode+1];

	tree[treenode].maximum = max(left.maximum , right.maximum);
	tree[treenode].smaximum = min(max(left.smaximum , right.maximum),max(left.maximum , right.smaximum));
}

node query(node* tree, int start, int end, int treenode, int left, int right)
{
	// Completely outside the given range
	if(start>right || end<left)
	{
		node x;
		x.maximum = x.smaximum = INT_MIN;
		return x;
	}

	// Completely inside the given range
	if(start>=left && end<=right)
		return tree[treenode];

	// Partially inside and partially outside
	int mid = (start + end)/2 ;
	node ans1 = query(tree, start, mid, 2*treenode, left, right);
	node ans2 = query(tree, mid+1, end, 2*treenode+1, left, right);
	node ans3;
	ans3.maximum =  max(ans1.maximum , ans2.maximum);
	ans3.smaximum = min( max(ans1.smaximum , ans2.maximum), max(ans1.maximum , ans2.smaximum) );
	return ans3;
}

int main() 
{
	int arr[100005];
	int N,Q;
	cin>>N;
	for (int i = 0; i < N; ++i)
	{
		cin>>arr[i];
	}

	node *tree = new node [3*N];

	
	buildTree(arr,tree,0,N-1,1); //start = 0; end = 8; starting with index =1;

	cin>>Q;
	char q;
	int l,r;
	for (int i = 0; i < Q; ++i)
	{
		cin>>q>>l>>r;
		if(q=='Q')
		{
			node ans = query(tree, 0, N-1, 1, l-1, r-1);
			cout<<ans.maximum+ans.smaximum<<endl;
		}
		else if(q=='U')
		{
			updateTree(arr, tree, 0, N-1, 1, l-1, r);
		}
	}
	return 0;
}
