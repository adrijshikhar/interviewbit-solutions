#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int binarySearch(vector<int> A, int B, bool firstElem)
{
  int result = -1, low = 0, high = A.size() - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (A[mid] < B)
    {
      low = mid + 1;
    }
    else if (A[mid] > B)
    {
      high = mid - 1;
    }
    else
    {
      result = mid;
      if (firstElem)
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
  }
  return result;
}

int findCount(const vector<int> &A, int B)
{
  int count = 0;

  int firstIndex = binarySearch(A, B, true);
  if (firstIndex == -1)
  {
    return 0;
  }

  int lastIndex = binarySearch(A, B, false);
  count = lastIndex - firstIndex + 1;
  return count;
}

int main()
{
  vector<int> A = {0, 1, 2, 3, 4, 5, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 10};
  int v2 = findCount(A, 11);

  cout << v2;

  return 0;
}
