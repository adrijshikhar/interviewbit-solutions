#include <bits/stdc++.h>

using namespace std;

int titleToNumber(string A)
{
  transform(A.begin(), A.end(), A.begin(), ::toupper);

  int n = A.size(), num = 0, k = 0;

  int charNum;

  for (int j = A.size() - 1; j >= 0; j--)
  {
    charNum = int(A[j]) - 64;
    num += (pow(26, n - 1 - j) * charNum);
    k++;
  }

  return num;
}

int main()
{
  string v1 = "Z";
  int v2 = titleToNumber(v1);
  cout << v2 << " ";
  return 0;
}
