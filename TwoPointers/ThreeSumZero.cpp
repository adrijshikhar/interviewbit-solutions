#include <bits/stdc++.h>

using namespace std;
// Use set concept
vector<vector<int>> threeSum(vector<int> &A)
{
  sort(A.begin(), A.end());

  vector<vector<int>> ans;
  if (A.size() < 2)
  {
    return ans;
  }
  int low = 0, high = A.size() - 1;
  long long int s = 0;
  for (int i = 0; i < A.size() - 2; i++)
  {
    low = 0;
    high = A.size() - 1;
    while (low < high)
    {
      s = A[low] + A[high] + A[i];

      if (s == 0 && (i != low && i != high))
      {
        int flag = 1;
        vector<int> pans{A[low], A[high], A[i]};
        sort(pans.begin(), pans.end());
        for (int j = 0; j < ans.size(); j++)
        {
          if ((ans[j][0] == pans[0]) && (ans[j][1] == pans[1]) && (ans[j][2] == pans[2]))
          {
            flag = 0;
            break;
          }
        }
        if (flag == 1)
        {
          ans.push_back(pans);
        }
      }
      if (s > 0)
      {
        high--;
      }
      else
      {
        low++;
      }
    }
  }

  return ans;
}

int main()
{
  vector<int> v1{
      1, -4, 0, 0, 5, -5, 1, 0, -2, 4, -4, 1, -1, -4, 3, 4, -1, -1, -3};
  vector<vector<int>> v2 = threeSum(v1);
  sort(v2.begin(), v2.end());

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
