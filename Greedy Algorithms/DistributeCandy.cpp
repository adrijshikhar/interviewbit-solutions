#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &ratings)
{
  int n = ratings.size();
  vector<int> candies(n);
  for (int i = 0; i < n; i++)
  {
    candies[i] = 1;
  }
  for (int i = 1; i < n; i++)
  {
    if (ratings[i] == ratings[i - 1])
      continue;

    else if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1])
      candies[i] = candies[i - 1] + 1;
    else
    {
      int j = i - 1;
      while (j >= 0 && ratings[j] > ratings[j + 1] & candies[j] <= candies[j + 1])
      {
        candies[j] = candies[j + 1] + 1;
        j--;
      }
    }
  }
  int ans = candies[0];
  for (int i = 1; i < n; i++)
    ans += candies[i];
  return ans;
}

//approach 2
int candy2(vector<int> &A)
{
  int n = A.size(), sum = 0, f = 0;

  vector<int> v(A.size(), 1);

  set<int> C;

  for (int k = 0; k < n; k++)
    C.insert(A[k]);
  auto it = C.begin();

  while (it != C.end())
  {
    f = 0;
    for (int j = 0; j < A.size(); j++)
    {
      if (*it < A[j])
      {
        v[j]++;
        f++;
      }
    }
    if (f == 0)
      break;
    it++;
  }

  for (int i = 0; i < n; i++)
    sum += v[i];

  return sum;
}

int main()
{
  vector<int> v1{1, 5, 2, 1};
  int v2 = candy(v1);
  cout << v2;
  return 0;
}
