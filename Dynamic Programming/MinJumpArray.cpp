#include <bits/stdc++.h>
using namespace std;

// top down
int minJump(int i, vector<int> &A)
{
  if (i >= A.size())
    return INT_MAX;
  if (i == A.size() - 1)
    return 0;

  int steps = A[i];
  int minSteps = INT_MAX;
  for (int j = 1; j <= steps; j++)
    minSteps = min(minSteps, minJump(j + i, A));
  return minSteps + 1;
}

// approach 2
int jump(vector<int> &A)
{
  int jumps = 0, current_range = 0, next_range = 0;

  for (int i = 0; i <= current_range; i++)
  {
    if (i == A.size() - 1)
      return jumps;

    next_range = max(next_range, A[i] + i);

    if (i == current_range)
    {
      jumps++;
      current_range = next_range;
    }
  }
  return -1;
}

int main()
{
  vector<int> v1{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  int v2 = minJump(0, v1);
  cout << v2;
  return 0;
}
