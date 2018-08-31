#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
#define limit 32000
void PrintVector(V arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}

L gcd(l a,l b)
{
	//2nd var is big
	if(a<b)
		gcd(b,a);

	//base case
	if(b==0)
		return a;
		
	return gcd(b,a%b);
}
L modBigInt(string S, L b)
{
	L temp=0;
	for (L i = 0; i < S.length(); ++i)
	{
		temp = ( temp*10 + (S[i]-'0') ) % b ;
		// cout<<temp<<endl;
	}
	return temp;
}
int main()
{
	L t;
	cin>>t;
	L b;
	string S;
	while(t--)
	{
		cin>>b;
		cin>>S;
		L a
		if(b==0)
			cout<<S<<endl;
		else
		{
			a = modBigInt(S,b);
			cout<<gcd(b,a)<<endl;
		}
	}
	return 0;
}