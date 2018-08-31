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

void buildTreeEven(int* arr, int* tree, int start, int end, int treenode)
{
	if(start==end)
	{
		if(arr[start]%2==0)
			tree[treenode] = 1;
		else
			tree[treenode] = 0;
		return;
	}
	int mid = (start + end)/2 ;

	buildTreeEven(arr, tree, start, mid, 2*treenode);
	buildTreeEven(arr, tree, mid+1, end, 2*treenode+1);

	tree[treenode] = (tree[2*treenode] + tree[2*treenode+1]);
}
void buildTreeOdd(int* arr, int* tree, int start, int end, int treenode)
{
	if(start==end)
	{
		if(arr[start]%2==0)
			tree[treenode] = 0;
		else
			tree[treenode] = 1;
		return;
	}
	int mid = (start + end)/2 ;

	buildTreeOdd(arr, tree, start, mid, 2*treenode);
	buildTreeOdd(arr, tree, mid+1, end, 2*treenode+1);

	tree[treenode] = (tree[2*treenode] + tree[2*treenode+1]);
}
void updateTreeEven(int* arr, int* tree, int start, int end, int treenode, int idx, int value)
{
	if(start==end)
	{
		arr[idx] = value;

		if(value%2==0)
			tree[treenode] = 1;
		else
			tree[treenode] = 0;

		return;
	}

	int mid = (start + end)/2 ;

	if(idx > mid)
		updateTreeEven(arr, tree, mid+1, end, 2*treenode+1, idx, value);
	else
		updateTreeEven(arr, tree, start, mid, 2*treenode, idx, value);

	tree[treenode] = (tree[2*treenode] + tree[2*treenode+1]);
}
void updateTreeOdd(int* arr, int* tree, int start, int end, int treenode, int idx, int value)
{
	if(start==end)
	{
		arr[idx] = value;

		if(value%2==0)
			tree[treenode] = 0;
		else
			tree[treenode] = 1;

		return;
	}

	int mid = (start + end)/2 ;

	if(idx > mid)
		updateTreeOdd(arr, tree, mid+1, end, 2*treenode+1, idx, value);
	else
		updateTreeOdd(arr, tree, start, mid, 2*treenode, idx, value);

	tree[treenode] = (tree[2*treenode] + tree[2*treenode+1]);
}
int query(int* tree, int start, int end, int treenode, int left, int right)
{
	// Completely outside the given range
	if(start>right || end<left)
		return 0;

	// Completely inside the given range
	if(start>=left && end<=right)
		return tree[treenode];

	// Partially inside and partially outside
	int mid = (start + end)/2 ;
	int ans1 = query(tree, start, mid, 2*treenode, left, right);
	int ans2 = query(tree, mid+1, end, 2*treenode+1, left, right);

	return (ans1+ans2);
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

	int *treeEven = new int [4*N];
	int *treeOdd = new int [4*N];
	for (int i = 0; i < 4*N; ++i)
	{
		treeEven[i]=-1;
		treeOdd[i]=-1;
	}

	buildTreeEven(arr,treeEven,0,N-1,1); //start = 0; end = 8; starting with index =1;
	buildTreeOdd(arr,treeOdd,0,N-1,1);
	for (int i = 1; i < 4*N; ++i)
			cout<<treeEven[i]<<" ";
	cout<<endl;
	for (int i = 1; i < 4*N; ++i)
			cout<<treeOdd[i]<<" ";
	cout<<endl;
	cin>>Q;
	int q,l,r,ans;
	for (int i = 0; i < Q; ++i)
	{
		cin>>q>>l>>r;
		if(q==0)
		{
			updateTreeOdd(arr, treeOdd, 0, N-1, 1, l-1, r);
			updateTreeEven(arr, treeEven, 0, N-1, 1, l-1, r);
		}
		else if(q==1)
		{
			ans = query(treeEven, 0, N-1, 1, l-1, r-1);
			cout<<ans<<endl;
		}
		else if(q==2)
		{
			ans = query(treeOdd, 0, N-1, 1, l-1, r-1);
			cout<<ans<<endl;
		}
		cout<<"Even  ";
		for (int i = 1; i < 4*N; ++i)
			cout<<treeEven[i]<<" ";
		cout<<endl;
		cout<<"Odd  ";
		for (int i = 1; i < 4*N; ++i)
				cout<<treeOdd[i]<<" ";
		cout<<endl;
	}
	return 0;
}