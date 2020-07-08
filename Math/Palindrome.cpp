#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int isPalindrome(int A)
{
  if (A < 0)
  {
    return false;
  }

  string str = to_string(A);
  int n = str.size(), flag = 1;
  for (int i = 0; i < n / 2; i++)
  {
    if (str.at(i) != str.at(n - 1 - i))
    {
      flag = 0;
      break;
    }
  }

  return flag;
}

int main()
{
  int v1 = -121;
  int v2 = isPalindrome(v1);
  cout << v2 << " ";
  return 0;
}
