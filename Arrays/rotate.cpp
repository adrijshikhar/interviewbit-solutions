#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> rotateArray(vector<int> &A, int B)
{
  B = B % A.size();
  vector<int> ret;
  for (int i = B; i < A.size(); i++)
  {
    ret.push_back(A[i]);
  }
  for (int i = 0; i < B; i++)
  {
    ret.push_back(A[i]);
  }
  return ret;
}

int main()
{
  vector<int> v1{1, 2, 3, 4, 5, 6, 7};
  vector<int> v2 = rotateArray(v1, 10);
  for (auto i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }

  return 0;
}
