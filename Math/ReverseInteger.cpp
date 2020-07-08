#include <bits/stdc++.h>

using namespace std;

int reverse(int A)
{
  int neg = 0;
  if (A < 0)
  {
    neg = 1;
  }

  if (neg)
  {
    A = A * -1;
  }
  string str = to_string(A);
  if (neg)
  {
    str.append("-");
  }
  std::reverse(str.begin(), str.end());
  long long int revNum = stoll(str);
  if (revNum < INT32_MAX && revNum > INT32_MIN)
  {
    return revNum;
  }

  return 0;
}

int main()
{
  int v1 = 2147483649;
  int v2 = reverse(v1);
  cout << v2 << " ";
  return 0;
}
