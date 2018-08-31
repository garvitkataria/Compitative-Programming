#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
#define limit 32000
int PrintVector(V arr1)
{
	int count=0;
    for (int i = 0; i < arr1.size(); ++i)
    {
    	if(arr1[i])
    		count++;
        	// cout<<i<<' ';
    }
    return count;
}
int main()
{
	int n,flag,count;
	cin>> n;
	
	V A(n+1,1);
	A[0]=0;
	A[1]=0;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if(A[i])
		{
			for (int j = i*i; j <= n ; j+=i)
				A[j]=0;
		}
	}
	cout<<PrintVector(A)<<endl;

	return 0;
}