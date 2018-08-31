#include<bits/stdc++.h>
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
typedef vector< pair<L,L> > Y;
#define limit 32000
#define MAX 2000001
#define MOD 1000000007
#define pb push_back
#define mp make_pair
V* SeivesFactors()
{
	V* A = new V();
	for (L i = 0; i < MAX; ++i)
		A->pb(i);
	
	for (L i = 2; i < MAX; ++i)
	{
		if(A->at(i)==i)
		{
			for (int j = 2*i; j < MAX; j+=i)
			{
				if(A->at(j)==j)
					A->at(j)=i;
			}
		}
	}
	
	// V* Factors =new V();
	// L f,oldf;
	// while(n!=1)
	// {
	// 	f = A->at(n);
	// 	if(oldf!=f)
	// 		Factors->pb(f);	
	// 	n=n/f;
	// 	oldf=f;
	// }
	return A;
}
V* TotalFactors(L n,V*A)
{
	V* Factors =new V();
	L f,oldf;
	while(n!=1)
	{
		f = A->at(n);
		if(oldf!=f)
			Factors->pb(f);	
		n=n/f;
		oldf=f;
	}
	return Factors;
}
void StrangeOrder(L n)
{
	V *A = SeivesFactors(); //nloglogn
	V Marked;
	V Order;
	for (L i = 0; i <= n; ++i) //n
		Marked.pb(0);

	L f;
	for (int i = n; i >= 1; --i)
	{
		if(Marked[i]==0)
		{
			Order.pb(i);
			V *FactorsArr = TotalFactors(i,A);
			for (int k = FactorsArr->size()-1; k >=0 ; --k)
			{	
				f=FactorsArr->at(k);
				// cout<<"Y"<<i<<" "<<f<<endl;
				
				for (int j = i-f; j >=1 ; j-=f)
				{
					if(Marked[j]==0)
						Order.pb(j);
					Marked[j]=1;
				}	
			}
		}
		sort(Order.begin(),Order.end());
		for (int i = Order.size()-1; i >=0 ; --i)
		{
			cout<<Order[i]<<" ";
		}
		Order.clear();
	}
	cout<<endl;
}
int main()
{
	L n;
	cin>>n;
	StrangeOrder(n);
	// V *A = SeivesFactors(n);
	// for (int i = 0; i < A->size(); ++i)
	// 	cout<<i<<"  "<<A->at(i)<<endl;
	return 0;
}