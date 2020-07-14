#include <bits/stdc++.h>

using namespace std;

void backtrack(vector<int> &A, int st, vector<vector<int>> &v, vector<int> &v1)
{
  v.push_back(v1);
  for (int i = st; i < A.size(); i++)
  {
    v1.push_back(A[i]);
    backtrack(A, i + 1, v, v1);
    v1.pop_back();
  }
}

vector<vector<int>> subsets(vector<int> &A)
{
  sort(A.begin(), A.end());

  vector<vector<int>> v;
  vector<int> v1;

  backtrack(A, 0, v, v1);

  return v;
}

int main()
{
  vector<int> v1{1, 2, 3, 4};
  vector<vector<int>> v2 = subsets(v1);

  for (int i = 0; i < v2.size(); i++)
  {
    for (int j = 0; j < v2[i].size(); j++)
    {
      cout << v2[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
