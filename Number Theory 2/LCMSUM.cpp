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
#define pb push_back
#define mp make_pair
V* SeivesFactors(int n)
{
	V* A = new V();
	V* B = new V();
	for (L i = 0; i <= n; ++i)
		A->pb(i);
	
	// for (L i = 2; i*i <= n; ++i)
	// {
	// 	if(A->at(i)==i)
	// 	{
	// 		for (int j = 2*i; j <= n; j+=i)
	// 		{
	// 			if(A->at(j)==j)
	// 				A->at(j)=i;
	// 		}
	// 	}
	// }
	// while(n>1)
	// {
	// 		B->pb(A->at(n));
	// 		n=n/(A->at(n));
	// }
	for (L i = 2; i <= n; ++i)
	{
		if(n % A->at(i) == 0)
			B->pb(A->at(i));
	}


	return B;
}
V eulerPhi(int n){

	V phi;
	for(int i=0;i<=n;i++){
		phi.pb(i);
	}

	for(int i=2;i<=n;i++)
	{
		if(phi[i] == i)
		{
			phi[i] = i-1;
			for(int j=2*i;j<=n;j+=i)
			{
				phi[j] = (phi[j]*(i-1))/i;
			}
		}
	}
	return phi;

}
int main()
{
	L n;
	cin>>n;
	V phi,*fac;
	fac = SeivesFactors(n);
	phi = eulerPhi(MAX);
	// cout<<"HI"<<phi[4]<<endl;
	// cout<<fac->size();
	// for(int i=0;i<fac->size();i++){
	// 	cout << "Euler Totient Phi For " << i << "Is :" << fac->at(i)<<endl;
	// }

	L sum=0;
	for (int i = 0; i < fac->size(); ++i)
	{
		sum+=phi[fac->at(i)]*fac->at(i);
		// sum%=MOD;
	}
	sum=(sum+2);
	sum*=n;
	sum/=2;
	cout<<sum<<endl;
	return 0;
}