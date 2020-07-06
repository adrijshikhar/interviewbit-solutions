#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int binarySearch(vector<int> A, int B)
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
      return 1;
    }
  }
  return 0;
}

int searchMatrix(vector<vector<int>> &A, int B)
{
  int width = A[0].size() - 1, result = 0;

  vector<int> C;

  for (auto i = 0; i < A.size(); i++)
  {
    if (A[i][0] <= B && B <= A[i][width])
    {
      C = A[i];
      break;
    }
  }

  result = binarySearch(C, B);
  return result;
}

int main()
{
  vector<vector<int>> v1{{1, 2, 3}, {
                                        4,
                                        5,
                                        6,
                                    },
                         {7, 8, 9},
                         {10, 11, 12}};

  int v2 = searchMatrix(v1, 5);
  cout << v2;

  return 0;
}
