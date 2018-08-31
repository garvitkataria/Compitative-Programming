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
void PrintVector(V arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}
Y* Factors(L x)
{
	Y* Factors = new Y();
	L count,num;
	num=x;
	if(x==1)
	{
		Factors->pb( mp(1,1) );
	}
	for (int i = 2; i*i <= x; ++i)
	{
		count=0;
		while(x%i==0)
		{
			count++;
			x/=i;
		}
		Factors->pb( mp(i,count) );
	}
	if(x!=1)
		Factors->pb( mp(x,1) );
    return Factors;
}
// A1 is bigger than A2
bool IsDivisible(Y* A1,Y* A2)
{
	int j=0;
	for (int i = 0; i < A2->size(); ++i)
	{
		while(A1->at(j).first != A2->at(i).first)
		{
			j++;
			if(j>=A1->size())
				return false;
		}

		if(A1->at(j).second < A2->at(i).second)
			return false;
	}
	return true;
}
Y* AddFactors(Y* pdct,L x)
{
	Y* addedFactors = new Y();
	Y* A = Factors(x);
	L m = pdct->size();
	L n = A->size();
	L i=0,j=0,temp1,temp2;
	while(i<m && j<n)
	{
		if(pdct->at(i).first > A->at(j).first)
			addedFactors->pb(A->at(j++));
		
		else if(pdct->at(i).first < A->at(j).first)
			addedFactors->pb(pdct->at(i++));
		else
		{
			temp1 = pdct->at(i).first;
			temp2 = A->at(j).second + pdct->at(i).second;
			addedFactors->pb(mp(temp1,temp2));
			i++;j++;
		}
	}
	while(i<m)
		addedFactors->pb(pdct->at(i++));

	while(j<n)
		addedFactors->pb(A->at(j++));
	return addedFactors;
}
Y* ReduceFactors(Y* pdct,L x)
{
	// Y* addedFactors = new Y();
	Y* A = Factors(x);
	L m = pdct->size();
	L n = A->size();
	L i=0,j=0,temp1,temp2;
	while(i<m && j<n)
	{
		if(pdct->at(i).first > A->at(j).first)
			j++;
		
		else if(pdct->at(i).first < A->at(j).first)
			i++;
		else
		{
			pdct->at(i++).second-=A->at(j++).second;
		}
	}
	return pdct;
}
void TotalNoOfDecks(V A,L k)
{
	L i=0, j=0, sum,n;
	n = A.size();
	Y* K_fact = Factors(k);
	Y* pdct = Factors(A[0]);
	sum=0;

	while(i<n && j<n)
	{
		while(IsDivisible(pdct,K_fact))
		{
			sum += n-j;	
			pdct = ReduceFactors(pdct,A[i]);
			i++;
		}
		j++;
		if(j==n)
		{
			cout<<sum<<endl;
			return;
		}
		pdct = AddFactors(pdct,A[j]);
	}
	cout<<sum<<endl;
	return;
}
int main()
{
	L n,k,temp;
	V A;
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		A.pb(temp);
	}
	TotalNoOfDecks(A,k);
	return 0;
}