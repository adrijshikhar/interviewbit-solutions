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

vector<int> searchRange(const vector<int> &A, int B)
{
  vector<int> count;

  int firstIndex = binarySearch(A, B, true);
  if (firstIndex == -1)
  {
    count.push_back(-1);
    count.push_back(-1);
    return count;
  }

  int lastIndex = binarySearch(A, B, false);
  count.push_back(firstIndex);
  count.push_back(lastIndex);
  return count;
}

int main()
{
  vector<int> A = {0, 1, 2, 3, 4, 5, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 10};
  vector<int> v2 = searchRange(A, 6);

  for (auto i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }

  return 0;
}
