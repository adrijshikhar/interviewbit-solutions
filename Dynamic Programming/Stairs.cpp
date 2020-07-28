#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<ll, ll> mp;
ll stairs(ll n)
{
  if (n <= 2)
    return 1;

  if (mp.find(n - 1) == mp.end())
    mp[n - 1] = stairs(n - 1);

  if (mp.find(n - 2) == mp.end())
    mp[n - 2] = stairs(n - 2);

  return mp[n - 1] + mp[n - 2];
}

int main()
{
  ll v1 = 3;
  ll v2 = stairs(v1);

  cout << v2 << " ";

  return 0;
}
