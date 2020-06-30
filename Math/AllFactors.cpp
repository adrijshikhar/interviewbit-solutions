#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> allFactors(int A)
{
  vector<int> B, C;

  for (int i = 1; i <= sqrt(A); i++)
  {
    if (A % i == 0)
    {
      B.push_back(i);
      if (i != sqrt(A))
      {
        C.push_back(A / i);
      }
    }
  }

  for (int j = C.size() - 1; j >= 0; j--)
  {
    B.push_back(C[j]);
  }

  return B;
}

int main()
{
  int v1 = 100;
  vector<int> v2 = allFactors(v1);
  for (auto i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }
  return 0;
}
