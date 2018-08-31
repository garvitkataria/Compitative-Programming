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
	int value,weight;
};

bool compare(Item a, Item b)
{
	double fvalue1 = (double)a.value/a.weight;
	double fvalue2 = (double)b.value/b.weight;

	return fvalue1 > fvalue2;
}

double F_KnapSnack(int W, Item arr[], int n)
{
	sort(arr,arr+n,compare);

	int CurrW = 0;
	double fValue = 0;
	for (int i = 0; i < n; ++i)
	{
		if(arr[i].weight+CurrW <= W)
		{
			CurrW+=arr[i].weight;
			fValue += arr[i].value;
		}
		else
		{
			fValue += (double)arr[i].value * ( W - CurrW )/arr[i].weight ;
			break;
		}	
	}
	return fValue;
}

int main()
{
	int W=70;
	Item arr[3] = {{60,20},{70,15},{80,40}};
	cout<<" MAX Value :"<<F_KnapSnack(W,arr,3);
	return 0;
}