#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;

void PrintVector(V arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}
void BinarySearch()
{

}
int main()
{
    L N,C,t,temp;
    V arr1 ;
    cin>>t;
    while(t--)
    {
        cin>>N>>C;
        for (int i = 0; i < N; ++i)
        {
            cin>>temp;
            arr1.push_back(temp);
        }
        sort(arr1.begin(), arr1.end());
        // PrintVector(arr1);

        int cow;
        int pos;
        int i,ans;
        //distance ka loop
        for (i = 1; i <= arr1[N-1]; ++i)
        {
            cow=1;
            pos=arr1[0];
            // cout<<i<<endl;
            for (int j = 1; j < N; ++j)
            {
                if (arr1[j]-pos>=i)
                {
                    cow++;
                    pos=arr1[j];
                    // cout<<i<<' '<<pos<<' '<<cow<<endl;
                }
            }
            if(cow>=C)
            {
                // cout<<"Yes\n";

            }
            else
                {
                    // cout<<"No\n";
                    cout<<i-1<<endl;
                    break;
                }
        }
    }
    return 0;
}