#include <bits/stdc++.h>

using namespace std;

unsigned int reverse(unsigned int A)
{
  unsigned int num = 0;
  string B;
  for (int i = 0; i < 32; i++)
  {
    if ((A & 1 << i) != 0)
    {
      B.append("1");
    }
    else
    {
      B.append("0");
    }
  }
  cout << B << endl;
  int s = B.size();
  for (int i = 0; i < s; i++)
  {
    int ch = B[i] - 48;
    num += (ch * pow(2, s - i - 1));
  }

  return num;
}

int main()
{
  int v1 = 3;
  unsigned int v2 = reverse(v1);
  cout << v2;

  return 0;
}
