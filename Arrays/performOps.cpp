#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> performOps(vector<vector<int>> &A)
{
  vector<vector<int>> B;
  B.resize(A.size());
  for (int i = 0; i < A.size(); i++)
  {
    B[i].resize(A[i].size());
    for (int j = 0; j < A[i].size(); j++)
    {
      B[i][A[i].size() - 1 - j] = A[i][j];
    }
  }
  return B;
}

int main()
{
  vector<vector<int>> v1{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  vector<vector<int>> B = performOps(v1);

  for (int i = 0; i < B.size(); i++)
  {
    for (int j = 0; j < B[i].size(); j++)
      cout << B[i][j] << " ";
  }w

  return 0;
}
