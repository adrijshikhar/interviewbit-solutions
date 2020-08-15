#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<ll, ll> mp;
ll maximiseRobbery(vector<ll> &v, int i)
{
  if (i < 2)
    return 0;
  if (mp.find(i - 1) == mp.end())
    mp[i - 1] = maximiseRobbery(v, i - 1);

  if (mp.find(i - 2) == mp.end())
    mp[i - 2] = maximiseRobbery(v, i - 2);

  return max(mp[i - 1], (mp[i - 2] + v[i]));
}

int main()
{
  vector<ll> v1{2, 7, 9, 3, 1};
  int n = v1.size();
  mp[0] = v1[0];
  mp[1] = max(v1[0], v1[1]);
  ll v2 = maximiseRobbery(v1, n - 1);

  cout << v2 << " ";

  return 0;
}
