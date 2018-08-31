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


int MagicGridNo(vector< vector<int> > A, int n, int m )
{
    int **B = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        B[i] = new int[m];    
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            B[i][j]=-1;

    B[n-1][m-1]=1;

    //last row
    for (int i = m-2; i >=0; --i)
    {   
        B[n-1][i]=B[n-1][i+1]-A[n-1][i];
        if(B[n-1][i]<=0)
                B[n-1][i]=1;
    }
    //last column
    for (int i = n-2; i >=0; --i)
    {   
        B[i][m-1]=B[i+1][m-1]-A[i][m-1];
        if(B[i][m-1]<=0)
                B[i][m-1]=1;
    }

    for (int i = n-2; i >=0; --i)
    {
        for (int j = m-2; j >=0; --j)
        {
            B[i][j]=min(B[i+1][j],B[i][j+1]) - A[i][j];
            if(B[i][j]<=0)
                B[i][j]=1;
        }
    }

    // for (int i = 0; i < n; ++i)
    // {   for (int j = 0; j < m; ++j)
    //         cout<<B[i][j]<<' ';
    //     cout<<endl;
    // }
    return B[0][0];
}
int main()
{
    int t ,n , m, temp;
    vector< vector<int> > A;
    v a;
    cin>>t;
    while(t--)
    {
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
        cout<<MagicGridNo(A,n,m)<<endl;
        // for (int i = 0; i < n; ++i)
        // {    
        //     for (int j = 0; j < m; ++j)
        //         cout<<A[i][j]<<' ';
        //     cout<<endl;
        // }
        A.clear();
    }
	return 0;
}