#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<ll, ll> mp;
ll partyPeople(ll n)
{
  if (n == 0)
    return 0;

  if (mp.find(n - 1) == mp.end())
    mp[n - 1] = partyPeople(n - 1);

  if (mp.find(n - 2) == mp.end())
    mp[n - 2] = partyPeople(n - 2);

  return mp[n - 1] + (mp[n - 2] * (n - 1));
}

int main()
{
  ll v1 = 4;
  mp[1] = 1;
  mp[2] = 2;
  mp[3] = 4;

  ll v2 = partyPeople(v1);

  cout << v2 << " ";

  return 0;
}
