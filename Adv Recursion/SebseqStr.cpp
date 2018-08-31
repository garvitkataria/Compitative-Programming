#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int L;
typedef int l;
typedef vector<L> V;
typedef vector<l> v;
#define limit 32000
void PrintVector(V arr1)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
}
 
void subseqStr(string input, string output[],int totalSeq)
{
  if(input.empty())
  {
    output[0] = "";
    return;
  }
  string smallStr = input.substr(1);
  int totalSmallStr = totalSeq/2;
  subseqStr(smallStr, output, totalSmallStr);
  for (int i = 0; i < totalSmallStr; ++i)
  {
      output[i+totalSmallStr] = input[0]+output[i];
  }
}
int main()
{
  string input;
  cin>> input;
  int totalSeq=pow(2,input.length());
  cout<<totalSeq<<endl;
  string *output = new string[totalSeq];

  subseqStr(input, output, totalSeq);

  //Print Output
  for (int i = 0; i < totalSeq; ++i)
  {
    cout<<output[i]<<endl;
  }
	return 0;
}