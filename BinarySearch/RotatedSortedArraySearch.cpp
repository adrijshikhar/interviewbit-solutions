#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> A, int B, int i, int j)
{
  int result = -1, low = i, high = j;

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
  return result;
}

int search(const vector<int> &A, int B)
{
  int pivot = 0, ans = -1;
  for (int i = 0; i < A.size() - 1; i++)
  {
    if (A[i] > A[i + 1])
    {
      pivot = i + 1;
    }
  }
  if (pivot == 0)
  {
    pivot = A.size();
  }
  int sP = binarySearch(A, B, 0, pivot - 1);
  if (sP != -1)
  {
    ans = sP;
  }
  int sN = binarySearch(A, B, pivot, A.size() - 1);
  if (sN != -1)
  {
    ans = sN;
  }
  return ans;
}

int main()
{
  vector<int> v1{4, 5, 6, 7, 0, 1, 2, 3};
  int v2 = search(v1, 2);
  cout << v2;

  return 0;
}
