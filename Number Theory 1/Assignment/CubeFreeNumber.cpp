#include<bits/stdc++.h>
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
#define limit 32000
#define MAX 1000001
#define MOD 1000000007
#define pb push_back

void PrintVector(V arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}
V* CubeFreeNo()
{
	V* A = new V();
	for (L i = 0; i < MAX; ++i)
		A->pb(1);
	
	for (L i = 2; i <= 100; ++i)
	{
		if(A->at(i))
		{
			L k,j;
			j = i*i*i;
			k = 1;
			while(j*k < MAX)
			{
				A->at(j*k)=0;
				k++;
			}	
		}
	}
	L count=1;
	for (L i = 2; i < MAX; i++)
	{
		if(A->at(i))
		{
			count++;
			A->at(i)=count;
			// cout<<count<<endl;
		}
	}
	// for (int i = 1; i < 37; ++i)
		// cout<<i<<"  "<<A->at(i)<<endl;
	return A;
}
int main()
{
	 V *PreProcess = CubeFreeNo();
	 L t,n,o=1;
	 cin>>t;
	 while(o<=t)
	 {
	 	cin>>n;

	 	if(PreProcess->at(n))
	 		cout<<"Case "<<o<<": "<<PreProcess->at(n)<<endl;
	 	else
	 		cout<<"Case "<<o<<": "<<"Not Cube Free"<<endl;
	 	o++;
	 }

	return 0;
}