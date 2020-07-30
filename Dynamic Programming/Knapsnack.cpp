#include <bits/stdc++.h>

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

vector<int> maximiseProfit(vector<int> &p, vector<int> &w, int m)
{
  reverse(p.begin(), p.end());
  reverse(w.begin(), w.end());

  int n = w.size();
  vector<int> ans(n, 0);
  int mp = 0, mw = 0;
  for (int i = 0; i < n; i++)
  {
    if (mw + w[i] <= m)
    {
      mw += w[i];
      ans[i] = 1;
      mp += (w[i] * p[i]);
    }
  }
  reverse(ans.begin(), ans.end());

  return ans;
}

int main()
{
  vector<int> p{1, 2, 5, 6};
  vector<int> w{2, 3, 4, 5};
  int m = 8;
  vector<int> v2 = maximiseProfit(p, w, m);
  for (int i = 0; i < v2.size(); i++)
    cout << v2[i];

  return 0;
}