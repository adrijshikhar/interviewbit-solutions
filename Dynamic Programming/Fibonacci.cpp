#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<ll, ll> mp;
ll fibonacci(ll n)
{
  if (n <= 2)
    return 1;

  if (mp.find(n - 1) == mp.end())
    mp[n - 1] = fibonacci(n - 1);

  if (mp.find(n - 2) == mp.end())
    mp[n - 2] = fibonacci(n - 2);

  return mp[n - 1] + mp[n - 2];
}

int main()
{
  ll v1 = 100;
  ll v2 = fibonacci(v1);

  cout << v2 << " ";

  return 0;
}
