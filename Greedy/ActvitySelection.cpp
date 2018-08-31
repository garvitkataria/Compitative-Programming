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

struct Item
{
	int S,F;
};

bool compare(Item a, Item b)
{	
	return a.F < b.F;

}

int KnapSnack( Item arr[], int n)
{
	sort(arr,arr+n,compare);
	int i=0,j=1;
	int count=1;
	while(j<n)
	{
		if(arr[i].F <= arr[j].S)
		{
			
			count++;
			i=j;
			j++;
		}
		else
			j++;
	}
	return count;
}
int main()
{
	int N;
	Item *arr;
	arr = new Item[1000009];
	cin>>N;
	for (int i = 0; i < N; ++i)
	{
		cin>>arr[i].S >> arr[i].F ;
	}
	cout<<KnapSnack(arr,N)<<endl;
	return 0;
}
