#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> squareSum(int A)
{
  vector<vector<int>> ans;
  for (int a = 1; a <= sqrt(A); a++)
  {
    for (int b = 1; b <= sqrt(A); b++)
    {
      if (a * a + b * b == A && a <= b)
      {
        vector<int> newEntry;
        newEntry.push_back(a);
        newEntry.push_back(b);
        ans.push_back(newEntry);
      }
    }
  }
  return ans;
}

int main()
{
  int v1 = 1;
  vector<vector<int>> v2 = squareSum(v1);
  for (vector<vector<int>>::size_type i = 0; i < v2.size(); i++)
  {
    for (vector<int>::size_type j = 0; j < v2[i].size(); j++)
    {
      std::cout << v2[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  return 0;
}
