#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(int A)
{
  string B, C = "1";
  int count = 0;
  if (A == 1)
  {
    B = C;
  }

  for (int i = 2; i <= A; i++)
  {
    int ch = C[0];
    for (int j = 0; j < C.size(); j++)
    {
      if (ch == int(C[j]))
      {
        count++;
      }
      else
      {
        B.push_back(char(count + 48));
        B.push_back(char(ch));
        ch = int(C[j]);
        count = 1;
      }
    }
    B.push_back(char(count + 48));
    B.push_back(char(ch));
    count = 0;
    C = B;
    B.clear();
  }

  return C;
}

int main()
{
  int v1 = 5;
  string v2 = longestCommonPrefix(v1);
  cout << v2;

  return 0;
}
