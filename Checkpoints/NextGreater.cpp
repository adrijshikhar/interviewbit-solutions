#include <bits/stdc++.h>

using namespace std;

vector<int> longestConsecutive(vector<int> &A)
{
  int n = A.size();
  vector<int> ans;
  stack<int> s;
  int i = n - 1;
  while (i >= 0)
  {
    if (s.empty())
    {
      ans.push_back(-1);
      s.push(A[i]);
      i--;
    }
    else if (s.top() > A[i])
    {
      ans.push_back(s.top());
      s.push(A[i]);
      i--;
    }
    else
      s.pop();
  }
  reverse(ans.begin(), ans.end());

  return ans;
}

int main()
{
  vector<int> v1{34, 35, 27, 42, 5, 28, 39, 20, 28};
  vector<int> v2 = longestConsecutive(v1);

  for (int i = 0; i < v2.size(); i++)
    cout << v2[i] << " ";

  return 0;
}
