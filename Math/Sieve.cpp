#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sieve(int A)
{
  vector<bool> prime;
  vector<int> B;
  prime.assign(A + 1, true);

  for (int p = 2; p * p <= A; p++)
  {
    if (prime[p] == true)
    {
      for (int i = p * p; i <= A; i += p)
        prime[i] = false;
    }
  }
  for (int i = 2; i < prime.size(); i++)
  {
    if (prime[i])
    {
      B.push_back(i);
    }
  }

  return B;
}

int main()
{
  int v1 = 100;
  vector<int> v2 = sieve(v1);
  for (auto i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }
  return 0;
}
