#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int searchInsert(const vector<int> &A, int B)
{

  int low = 0, high = A.size() - 1;

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
     return mid;
    }
  }
  return low;
}

int main()
{
  vector<int> A = {0, 1, 2, 3, 5, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 10};
  int v2 = searchInsert(A, 4);

  cout << v2;

  return 0;
}
