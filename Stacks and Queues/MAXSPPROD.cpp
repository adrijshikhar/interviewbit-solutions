#include <bits/stdc++.h>
using namespace std;

int maxSpecialProduct(vector<int> A)
{
  int n = A.size();
  stack<pair<int, int>> st;

  long long int larr[n], rarr[n];

  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && st.top().first <= A[i])
      st.pop();

    if (st.empty())
      larr[i] = 0;
    else
      larr[i] = st.top().second;
    st.push({A[i], i});
  }

  while (!st.empty())
    st.pop();

  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && st.top().first <= A[i])
      st.pop();

    if (st.empty())
      rarr[i] = 0;
    else
      rarr[i] = st.top().second;
    st.push({A[i], i});
  }

  long long int ans = -1;

  for (int i = 0; i < n; i++)
  {
    ans = max(ans, larr[i] * rarr[i]);
  }

  return ans % 1000000007;
}

int main()
{
  vector<int> v1{1, 4, 3, 4};
  int v2 = maxSpecialProduct(v1);
  cout << v2;
  return 0;
}
