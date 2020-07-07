#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> wave(vector<int> &A)
{
  sort(A.begin(), A.end());
  if (A.size() == 1)
  {
    return A;
  }

  for (int i = 0; i < A.size() - 1; i += 2)
  {
    if (A[i] == A[i + 1])
    {
      continue;
    }
    int temp = A[i];
    A[i] = A[i + 1];
    A[i + 1] = temp;
  }

  return A;
}

int main()
{
  vector<int> v1{
     1};
  vector<int> v2 = wave(v1);
  for (auto i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }

  return 0;
}
