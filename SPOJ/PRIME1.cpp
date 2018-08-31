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
int main()
{
	//GETTING PRIME NUMBERS TILL SQROOT(N)
		V arr1(limit,1);
		V prime;
		arr1[0]=arr1[1]=0;
		for (int i = 2; i < limit; ++i)
		{
			if(arr1[i]==1)
			{
					for (int j = i*i; j < limit ; j+=i)
					{
						arr1[j]=0;	
					}
			}
		}
		//putting primes to an array
		for (int i = 0; i < limit; ++i)
		{
			if(arr1[i]==1)
				prime.push_back(i);
		}
	L t;
	cin>>t;
	while(t--)
	{
		L m,n;
		cin>>m>>n;

		int flag=1;
		// printing prime from m to n
		for (int i = m; i <= n; ++i)
		{
			flag=1;
			int temp=sqrt(i);
			// cout<<temp;
			for (int j = 0; prime[j] <= temp; ++j)
			{
				if(i % prime[j] == 0)
				{
					flag=0;
					break;
				}
				// cout<<i<<prime[j]<<' '<<flag<<endl;
			}
			if(flag&&i!=0&&i!=1)
			{
				cout<<i<<endl;
			}
		}
	}
	cout<<endl;
	return 0;
}