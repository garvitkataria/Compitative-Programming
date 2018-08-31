#include<bits/stdc++.h>
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
typedef vector< pair<L,L> > Y;
#define limit 32000
#define MAX 10000001
#define MOD 1000000007
#define pb push_back
#define mp make_pair

V *F;
void PrintVector(V arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}
V* SeivesFactors()
{
	V* A = new V();
	for (L i = 0; i < MAX; ++i)
		A->pb(i);
	
	for (L i = 2; i*i < MAX; ++i)
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
	return A;
}
Y* Factors(L n,V*A)
{
	Y* Factors = new Y();
	L f,oldf;
	L count = 1;
	f = A->at(n);
	Factors->pb( mp(f,1) );
	n/=f;
	while(n!=1)
	{
		f = A->at(n);
		if(f==Factors->at(Factors->size()-1).first)
			Factors->at(Factors->size()-1).second++;
		else
			Factors->pb( mp(f,count) );
		n=n/f;
		oldf=f;
	}
	return Factors;
}

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
	// V *F = SeivesFactors();
	Y* addedFactors = new Y();
	Y* A = Factors(x,F);
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
	// V *F = SeivesFactors();
	Y* A = Factors(x,F);
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
	// V *F = SeivesFactors();
	L i=0, j=0, sum,n;
	n = A.size();
	Y* K_fact = Factors(k,F);
	Y* pdct = Factors(A[0],F);
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
	F = SeivesFactors();
	L n,k,temp;
	V A;
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		A.pb(temp);
	}
	TotalNoOfDecks(A,k);
	// V *F = SeivesFactors();
	// Y*A1 = Factors(A[0],F);
	// Y*A2 = Factors(k,F);
	// 	for (int i=0; i<A1->size(); i++)
 //    {
	// 	cout << A1->at(i).first << " "
	// 		<< A1->at(i).second << endl;
 //    }
 //    cout<<"==="<<endl;
 //    for (int i=0; i<A2->size(); i++)
 //    {
	// 	cout << A2->at(i).first << " "
	// 		<< A2->at(i).second << endl;
 //    }
	return 0;
}