#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
typedef set<L> S;
typedef set<l> s;

#define limit 32000

void PrintVector(V arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}

int getCodes(string input, string output[10000]) 
{
   if(input.empty())
   {
    output[0]="";
    return 1;
   }
   int oldCodes = getCodes(input.substr(1),output);
   for (int i = 0; i < oldCodes; ++i)
     output[i]=(char)((int)input[0]+48)+output[i];
   
   if(input.size()>=2)
   {
      int temp=((int)input[0]-48)*10 + ((int)input[1]-48);
      // cout<<temp<<endl;
      if( temp  <= 26)
      {
        string output2[10000];
        int oldCodes2 = getCodes(input.substr(2),output2);
        for (int i = 0; i < oldCodes2; ++i)
          output[i+oldCodes]=(char)(temp+96)+output2[i];

        return oldCodes+oldCodes2;
      }
    }
   return oldCodes;
}

int main()
{
  string input;
  string output[10000];
  cin>>input;
  // cout<<"test"<<(int)'a'<<(int)'1'<<endl;
  int x=getCodes(input, output);
  cout<<x<<endl;
  for (int i = 0; i < x; ++i)
    cout<<output[i]<<endl;

  return 0;
}