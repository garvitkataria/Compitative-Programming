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

int powOf2[100005];

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

	int left = tree[2*treenode];
	int right = tree[2*treenode+1];
	tree[treenode] = ((left*powOf2[end-mid])%3 + right)%3;
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

	tree[treenode] = ((tree[2*treenode]*powOf2[end-mid])%3 + tree[2*treenode+1])%3;
}

int query(int* tree, int start, int end, int treenode, int left, int right)
{
	// Completely outside the given range
	if(start>right || end<left)
		return -1;

	// Completely inside the given range
	if(start>=left && end<=right)
	{
		// cout<<start<<" "<<end<<" "<<treenode<<endl;
		return tree[treenode];
	}

	// Partially inside and partially outside
	int mid = (start + end)/2 ;
	int l = query(tree, start, mid, 2*treenode, left, right);
	int r = query(tree, mid+1, end, 2*treenode+1, left, right);
	if(l==-1)
		return r;
	else if(r==-1)
		return l;
	//cout<<"+"<<start<<end<<mid<<left<<right<<endl;
	if(right<end)
		return ((l*powOf2[right-mid])%3 + r)%3;
	else
		return ((l*powOf2[end-mid])%3 + r)%3;
}

int main() 
{
	int arr[100005];
	char S[100005];
	int N,Q;
	cin>>N;
	cin>>S;
	for (int i = 0; i < N; ++i)
	{
		if(S[i]=='1')
			arr[i]=1;
		else 
			arr[i]=0;
	}
	for (int i = 1; i < 100005; ++i)
	{
		if(i%2==0)
			powOf2[i]=1;
		else
			powOf2[i]=2;
	}

	int *tree = new int [4*N];
	buildTree(arr,tree,0,N-1,1); //start = 0; end = 8; starting with index =1;

	// for (int i = 1; i < 4*N; ++i)
	// {
	// 	cout<<tree[i]<<" ";
	// }cout<<endl;

	cin>>Q;
	int q,l,r;
	for (int i = 0; i < Q; ++i)
	{
		cin>>q;
		if(q==0)
		{
			cin>>l>>r;
			int ans = query(tree, 0, N-1, 1, l, r);
			cout<<ans<<endl;
		}
		else if(q==1)
		{
			cin>>l;
			updateTree(arr, tree, 0, N-1, 1, l, 1);
		}
	}
	return 0;
}
