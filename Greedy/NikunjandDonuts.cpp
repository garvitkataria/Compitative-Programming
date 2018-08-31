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

bool compare(int a, int b)
{	
	return a > b;

}

L KnapSnack( int arr[], int n)
{
	sort(arr,arr+n,compare);
	L pow=1;
	L count=0;
	for (int i = 0; i < n; ++i)
	{
		
		count += pow*arr[i];
		pow *= 2;
		//cout<<count<<endl;
	}
	return count;
}
int main()
{
	int N;
	int *arr;
	arr = new int[1000009];
	cin>>N;
	for (int i = 0; i < N; ++i)
	{
		cin>>arr[i];
	}
	cout<<KnapSnack(arr,N)<<endl;
	return 0;
}
