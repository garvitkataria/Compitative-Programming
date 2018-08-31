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
	int MaxSum;
	int Sum;
	int BestPriffixSum;
	int BestSuffixSum;
};

void buildTree(int* arr, node* tree, int start, int end, int treenode)
{
	if(start==end)
	{
		tree[treenode].MaxSum = (arr[start]);
		tree[treenode].Sum = arr[start];
		tree[treenode].BestPriffixSum = (arr[start]);
		tree[treenode].BestSuffixSum = (arr[start]);
		return;
	}
	int mid = (start + end)/2 ;

	buildTree(arr, tree, start, mid, 2*treenode);
	buildTree(arr, tree, mid+1, end, 2*treenode+1);

	node left = tree[2*treenode];
	node right = tree[2*treenode+1];

	tree[treenode].MaxSum = 
			max(left.MaxSum, 
				max(right.MaxSum,
					max(left.Sum+right.BestPriffixSum, 
						max(left.BestSuffixSum+right.Sum,
							left.BestSuffixSum+right.BestPriffixSum
							)
						)
					)
				);
	tree[treenode].Sum = left.Sum+right.Sum;
	tree[treenode].BestPriffixSum = max(left.BestPriffixSum, left.Sum+right.BestPriffixSum);
	tree[treenode].BestSuffixSum = max(right.BestSuffixSum, left.BestSuffixSum+right.Sum);

}

node query(node* tree, int start, int end, int treenode, int l, int r)
{
	node ans3;
	ans3.MaxSum = ans3.Sum = ans3.BestPriffixSum = ans3.BestSuffixSum = INT_MIN;
	// Completely outside the given range
	if(start>r || end<l)
		return ans3;

	// Completely inside the given range
	if(start>=l && end<=r)
		return tree[treenode];

	// Partially inside and partially outside
	int mid = (start + end)/2 ;

	node left = query(tree, start, mid, 2*treenode, l, r);
	node right = query(tree, mid+1, end, 2*treenode+1, l, r);

	

	ans3.MaxSum = 
		max(left.MaxSum, 
				max(right.MaxSum,
					max(left.Sum+right.BestPriffixSum, 
						max(left.BestSuffixSum+right.Sum,
							left.BestSuffixSum+right.BestPriffixSum
							)
						)
					)
				);
	ans3.Sum = left.Sum+right.Sum;
	ans3.BestPriffixSum = max(left.BestPriffixSum, left.Sum+right.BestPriffixSum);
	ans3.BestSuffixSum = max(right.BestSuffixSum, left.BestSuffixSum+right.Sum);
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
	int l,r;
	for (int i = 0; i < Q; ++i)
	{
		cin>>l>>r;
		node ans = query(tree, 0, N-1, 1, l-1, r-1);
		cout<<ans.MaxSum<<endl;
		for (int i = 1; i < 3*N; ++i)
		cout<<tree[i].MaxSum<<" "<<tree[i].Sum<<" "<<tree[i].BestPriffixSum<<" "<<tree[i].BestSuffixSum<<endl;
	cout<<"-------"<<endl;
	}
	return 0;
}
