#include <bits/stdc++.h>
#define MOD 10000003
using namespace std;

int maxp3(string A)
{
  vector<int> pos;
  for (int i = 0; i < A.size(); i++)
  {
    if (A[i] == 'x')
      pos.push_back(i);
  }
  int n = pos.size();
  long long int ans = 0;
  int mid = n / 2;
  int k = 1;
  for (int i = mid - 1; i >= 0; i--)
  {
    ans = (ans + pos[mid] - k - pos[i]) % MOD;
    k++;
  }
  k = 1;
  for (int i = mid + 1; i < n; i++)
  {
    ans = (ans + pos[i] - (pos[mid] + k)) % MOD;
    k++;
  }
  return ans % MOD;
}

int main()
{
  string v1 = ".x.x.x..x";
  int v2 = maxp3(v1);
  cout << v2;
  return 0;
}
