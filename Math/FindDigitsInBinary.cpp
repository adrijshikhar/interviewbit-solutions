#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string findDigitsInBinary(int A)
{
  string ans = "";
  int n = A;
  if(A==0){
    return "0";
  }
  while (n > 0)
  {
    ans = ans + to_string(n % 2);
    n = n / 2;
  }
  string revans;

  for (int n = ans.length() - 1; n >= 0; n--)
  {
    revans.push_back(ans[n]);
  }
  return revans;
}

int main()
{
  int v1 = 0;
  string v2 = findDigitsInBinary(v1);
  cout << v2;
  return 0;
}
