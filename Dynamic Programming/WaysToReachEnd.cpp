#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct hash_pair
{
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const
  {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};

unordered_map<pair<ll, ll>, ll, hash_pair> mp;
ll findNumberOfWays(ll i, ll j, ll &m, ll &n)
{
  if (i == m || j == n)
    return 1;
  if (mp.find(make_pair(i, j + 1)) == mp.end())
    mp[make_pair(i, j + 1)] = findNumberOfWays(i, j + 1, m, n);
  if (mp.find(make_pair(i + 1, j)) == mp.end())
    mp[make_pair(i + 1, j)] = findNumberOfWays(i + 1, j, m, n);

  return mp[make_pair(i, j + 1)] + mp[make_pair(i + 1, j)];
}

int main()
{
  ll v1 = 3, v3 = 2;

  ll v2 = findNumberOfWays(1, 1, v1, v3);

  cout << v2 << " ";

  return 0;
}
