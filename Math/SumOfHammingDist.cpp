#include <bits/stdc++.h>

using namespace std;

int hammingDistance(const vector<int> &A)
{
  long long int result = 0;
  int n = A.size();
  vector<int> bin(32, 0);

  for (int i = 0; i < n; i++)
  {
    long long int num = A[i], c = 0;
    while (num > 0)
    {
      if (num % 2 == 1)
      {
        bin[c]++;
      }
      num /= 2;
      c++;
    }
  }
  for (int i = 0; i < 32; i++)
  {
    result += (bin[i] * (n - bin[i]) * 2) % 1000000007;
  }

  return result;
}

int main()
{
  vector<int> v1{96, 96, 7, 81, 2, 13};
  int v2 = hammingDistance(v1);
  cout << v2 << " ";
  return 0;
}
