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
	int T,X,Y;
};

bool compare(Item a, Item b)
{
	if(a.T==b.T)
	{
		if(a.Y == b.Y)
		{
			return a.X < b.X;
		}
		return a.Y > b.Y;
	}
	return a.T < b.T;
}

double F_KnapSnack(int D, Item arr[], int n)
{
	sort(arr,arr+n,compare);
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<arr[i].T<<arr[i].X<<arr[i].Y<<endl;
	// }
	int Cost = 0;
	int CurrCost = 0;
	int Time = 0;
	int CurrY = 0;
	int BestY = 0;
	int Area=0;

	for (int i = 0; i < n; ++i)
	{	
		CurrCost = arr[i].X;
		Time =  arr[i].T;
		CurrY = arr[i].Y;

		if(Area+BestY <= D)
		{
			if(BestY < CurrY)
			{
				BestY = CurrY;
				Cost+=CurrCost;
			}
			Area+=BestY;
		}
		else
		{
			break;
		}	

	}

	// time
	 return Cost;
}

int main()
{
	int N,D;
	Item arr[100];
	cin>>N>>D;
	for (int i = 0; i < N; ++i)
	{
		cin>>arr[i].T >> arr[i].X >> arr[i].Y;
	}
	cout<<F_KnapSnack(D,arr,N)<<endl;
	return 0;
}
