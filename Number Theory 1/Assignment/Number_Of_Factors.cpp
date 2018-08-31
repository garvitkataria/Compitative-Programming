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

V* No_Of_Factors()
{
	V* A = new V();
	for (L i = 0; i < MAX; ++i)
		A->pb(0);
	
	for (L i = 2; i <= MAX; ++i)
	{
		if(A->at(i)==0)
		{
			for (int j = i; j < MAX; j+=i)
				A->at(j)++;
		}
	}
	
	// for (int i = 1; i <= 10; ++i)
	// 	cout<<i<<"  "<<A->at(i)<<endl;
	return A;
}
int main()
{
	int** M = new int*[11];
	for(int i = 0; i < 11; ++i)
    	M[i] = new int[MAX];

	L count;
	 V *PreProcess = No_Of_Factors();
	 for (int i = 0; i < 11; ++i)
	 {
	 	count = 0;
	 	M[i][0]=0;
	 	for (int j = 1; j < MAX; ++j)
	 	{
	 		if(PreProcess->at(j)==i)
	 		{	
	 			count++;
	 			M[i][j]=count;
	 		}
	 		else
	 			M[i][j]=count;
	 	}
	 }

	 L t,a,b,n;
	 cin>>t;
	 while(t--)
	 {
	 	cin>>a>>b>>n;
	 	L count=0;
	 	for (L i = a; i <= b; ++i)
	 	{
	 		if(PreProcess->at(i)==n)
	 			count++;
	 	}
	 	cout<<count<<endl;
	 	// cout<<"a,b -- "<<M[n][a-1]<<" "<<M[n][b]<<endl;
	 	// cout<<-M[n][a-1]+M[n][b]<<endl;
	 }
	return 0;
}