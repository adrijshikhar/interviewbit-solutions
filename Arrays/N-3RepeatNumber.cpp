#include <bits/stdc++.h>

using namespace std;

int repeatedNumber(const vector<int> &A)
{
  unordered_map<int, int> mp;
  int n = A.size();

  for (int i = 0; i < n; i++)
  {
    if (mp.find(A[i]) == mp.end())
    {
      mp[A[i]] = 1;
    }
    else
    {
      mp[A[i]]++;
    }
  }

  unordered_map<int, int>::iterator itr;
  for (itr = mp.begin(); itr != mp.end(); itr++)
  {
    if (n / 3 < itr->second)
    {
      return itr->first;
    }
  }
  return -1;
}

int main()
{
  vector<int> A{1, 2, 2, 1, 1, 1, 1, 2};

  int v2 = repeatedNumber(A);
  cout << v2;
  return 0;
}

