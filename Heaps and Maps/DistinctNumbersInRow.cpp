#include <bits/stdc++.h>

using namespace std;


vector<int> dNums(vector<int> &A, int B)
{
  vector<int> ans;
  int n = A.size();
  if (n < B)
  {
    return ans;
  }

  unordered_map<int, int> window;

  for (int i = 0; i < B; i++)
  {
    if (window.find(A[i]) == window.end())
      window[A[i]] = 1;
    else
      window[A[i]]++;
  }

  ans.push_back(window.size());

  for (int i = B; i < n; i++)
  {
    if (window[A[i - B]] == 1)
      window.erase(A[i - B]);
    else
      window[A[i - B]]--;

    if (window.find(A[i]) == window.end())
      window[A[i]] = 1;
    else
      window[A[i]]++;

    ans.push_back(window.size());
  }
  return ans;
}

int main()
{
  vector<int> v1{1, 2, 1, 3, 4, 3};
  vector<int> v2 = dNums(v1, 3);

  for (int i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }

  return 0;
}
