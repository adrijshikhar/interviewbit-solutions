#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int findMin(vector<int> &A)
{
  int low = 0, high = A.size() - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (A[low] <= A[high])
    {
      return A[low];
    }
    int next = mid + 1, prev = mid - 1;
    if (A[mid] <= A[next] && A[mid] <= A[prev])
    {
      return A[mid];
    }
    else if (A[mid] <= A[high])
    {
      high = mid - 1;
    }
    else if (A[mid] >= A[low])
    {
      low = mid + 1;
    }
  }
  return -1;
}

int main()
{
  vector<int> v1{
      6,
      7,
      10,
      2,
      3,
      4,
      5,
  };
  int v2 = findMin(v1);
  cout << v2;

  return 0;
}
