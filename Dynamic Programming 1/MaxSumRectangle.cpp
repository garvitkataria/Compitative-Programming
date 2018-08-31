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
    int best_sum=INT_MIN;
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

int MaxSumRec(vector< vector<int> > A, int n, int m )
{
    int l,r;
    l=r=0;
    V sumArr;
    for (int i = 0; i < n; ++i)
    {
        sumArr.pb(0);
    }
    int i,j,k, area=0,maxA=INT_MIN;
    for ( i = 0; i < n; ++i)
    {
        for ( j = i; j < n; ++j)
        {
            for ( k = 0; k < n; ++k)
            {
                sumArr[k] += A[k][j];
            }
            area = kadane(sumArr);
            if(area > maxA)
                maxA = area;
            // cout<<area<<endl;
        }

         // cout<<"l r:"<<i<<" "<<j<<endl;

        for (int j = 0; j < n; ++j)
        {
            // cout<<sumArr[j]<<' ';
            sumArr[j]=0;
        }
        // cout<<endl;

    }

    // for (int i = 0; i < n; ++i)
    //     cout<<sumArr[i]<<' ';
    // cout<<endl;

    return maxA;
}
int main()
{
    int t ,n , m, temp;
    vector< vector<int> > A;
    v a;

        cin>>n>>m;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin>>temp;
                a.pb(temp);
            }
            A.pb(a);
            a.clear();
        }
        cout<<MaxSumRec(A,n,m)<<endl;
        // for (int i = 0; i < n; ++i)
        // {    
        //     for (int j = 0; j < m; ++j)
        //         cout<<A[i][j]<<' ';
        //     cout<<endl;
        // }
        A.clear();

	return 0;
}