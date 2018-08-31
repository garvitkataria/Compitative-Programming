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
	int a,flag,count;
	cin>> a;
	flag=1;
	count=0;
	for (int i = 2; i < a; ++i)
	{
		flag=1;
		for (int j = 2; j <= sqrt(i); ++j)
		{
			if(i%j==0)
			{
				flag=0;
			}
		}
		if(flag)
		{
			// cout<<i<<endl;
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}