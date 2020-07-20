#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(const vector<int> A, int B)
{

  vector<int> res;

  if (A.size() < 2)
    return res;

  unordered_map<int, int> mp;

  for (int i = 0; i < A.size(); i++)
  {
    int k = B - A[i];

    if (mp.find(k) != mp.end())
    {
      res.push_back(mp[k] + 1);
      res.push_back(i + 1);

      return res;
    }
    if (mp.find(A[i]) == mp.end())
    {
      mp[A[i]] = i;
    }
  }

  return res;
}

int main()
{
  vector<int> v1{1, 1, 1, 1, 2, -2, 4, -4};
  vector<int> v2 = twoSum(v1, 10);
  for (int i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }

  return 0;
}
