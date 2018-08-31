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

void printAllPossibleCodes(string input,string output) 
{
  if(input.empty())
  {
    for (int i = 0; i <output.size(); ++i)
      cout<<output[i];
    cout<<endl;
    return;
  }
  output= output+(char)((int)input[0]+48) ;
  printAllPossibleCodes(input.substr(1),output);

  int temp=((int)input[0]-48)*10 + ((int)input[1]-48);
  if(temp<=26 && (input.size()>=2))
  {
    output=output.substr(0,output.size()-1)+(char)(temp+96);
    printAllPossibleCodes(input.substr(2),output);
  }
}

int main()
{
  string input;
  cin>>input;
  string output;
  int n=input.size();
  printAllPossibleCodes(input,output);
  return 0;
}