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
#define mod 1000000006
#define pb push_back
#define mp make_pair

int kadane(V A)
{
    int current_sum=0;
    int best_sum=0;
    for (int i = 0; i < A.size(); ++i)
    {
        current_sum += A[i];

        if(best_sum<current_sum)
            best_sum= current_sum;

        if(current_sum < 0)
            current_sum = 0;
    }
    return best_sum;
}

int main()
{
    l n,temp;
    V A;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>temp;
        A.pb(temp);
    }
    cout<<kadane(A)<<endl;
	return 0;
}