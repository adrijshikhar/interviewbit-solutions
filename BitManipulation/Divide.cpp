#include <bits/stdc++.h>

using namespace std;

int divide(int A, int B)
{

  if (A > INT_MAX)
  {
    return INT_MAX;
  }
  if (B == 0)
  {
    return INT_MAX;
  }
  long long dividend = A, divisor = B;
  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

  dividend = abs(dividend);
  divisor = abs(divisor);

  long long int quotient = 0, temp = 0;

  for (int i = 31; i >= 0; --i)
  {

    if (temp + (divisor << i) <= dividend)
    {
      temp += divisor << i;
      quotient |= 1LL << i;
    }
  }
  cout << quotient << " ";

  if (sign * quotient > INT_MAX || sign * quotient < INT_MIN)
  {
    return INT_MAX;
  }
  return sign * quotient;
}

int main()
{
  long long v1 = -2147483648;
  int v3 = 1;
  long long v2 = divide(v1, v3);
  cout << v2;

  return 0;
}
