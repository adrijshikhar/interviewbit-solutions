#include <bits/stdc++.h>

using namespace std;

vector<int> prevSmaller(vector<int> A)
{
  vector<int> ans;
  stack<int> s;
  s.push(-1);

  for (int i = 0; i < A.size(); i++)
  {
    if (s.top() < A[i])
    {
      ans.push_back(s.top());
      s.push(A[i]);
    }
    else
    {
      while (s.size() > 0)
      {
        if (s.top() < A[i])
        {
          ans.push_back(s.top());
          s.push(A[i]);
          break;
        }
        else
        {
          s.pop();
        }
      }
    }
  }

  return ans;
}

int main()
{
  vector<int> v1{3, 2, 1};
  vector<int> v2 = prevSmaller(v1);
  for (int i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }

  return 0;
}
