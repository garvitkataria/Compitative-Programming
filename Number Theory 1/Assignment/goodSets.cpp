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

void No_Of_Set(V A)
{
	V* B = new V();
	int k=0;
	for (L i = 0; i <= A[A.size()-1]; ++i)
	{
		B->pb(0);
		if(A[k]==i)
		{
			k++;
			B->at(i)=1;
		}
	}

	for (int i = 0; i < A.size()-1; ++i)
    {
    	for (int j = i+1; j < A.size(); ++j)
        {	
        	if(A[j]%A[i]==0)
        	{
        		B->at(A[j])+=B->at(A[i]);
        	}
        }
    }
    L count=0;
    for (int i = 0; i < B->size(); ++i)
    {
        // cout<<B->at(i)<<' ';
        if(B->at(i))
        {
        	count+=B->at(i);
        }
    }
    cout<<count<<endl;
    B->clear();
}
int main()
{
	 V A;
	 L t,n,temp;
	 cin>>t;
	 while(t--)
	 {
	 	cin>>n;
	 	for (int i = 0; i < n; ++i)
	 	{
	 		cin>>temp;
	 		A.pb(temp);
	 	}

	 	sort(A.begin(),A.end());
	 	No_Of_Set(A);
	 	A.clear();
	 }
	return 0;
}