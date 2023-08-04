#include<bits/stdc++.h>
using namespace std;
int sumofnum(string s,int index)
{
  if(index == 0) return s[index] - 48;
  return s[index] -48 + sumofnum(s,index -1);
}
int main()
{
    string num;
    cin>>num;
    int len = num.length();

    cout<<sumofnum(num,len-1);
    return 0;
}