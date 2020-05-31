#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &A)
{
  vector<int> maxArray;
  vector<int> B;
  long long int sum = 0;
  long long int maxSum = 0;
  for (int i = 0; i < A.size(); i++)
  {
    if (A[i] >= 0)
    {
      B.push_back(A[i]);
      sum += A[i];
      if (maxSum < sum)
      {
        maxSum = sum;
        maxArray = B;
      }
      else if (maxArray.size() <= B.size() && maxSum == sum)
      {
        maxSum = sum;
        maxArray = B;
      }
    }
    else
    {
      sum = 0;
      B.clear();
      continue;
    }
  }
  return maxArray;
}

int main()
{
  vector<int> v1{25150, 1412, 82797, 48381, 7065, -47699, -25129, -65483, -64607, -45322, -55176, 27224, 80366, 60444, 70285, -93898, -41133, 96576, -58266, 21711, -20614, -95737, 20591, -48762, -76197, -38588, -54873, 37304, 61200, -68960, 93947};
  vector<int> v2 = plusOne(v1);

  for (auto i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }

  return 0;
}
