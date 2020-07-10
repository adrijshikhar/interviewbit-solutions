#include <bits/stdc++.h>

using namespace std;

int amazingSubarray(string A)
{
  long long int ans = 0;
  for (int i = 0; i < A.size(); i++)
  {
    char c = tolower(A[i]);
    int ch = c;
    if (ch == 97 || ch == 101 || ch == 105 || ch == 111 || ch == 117)
    {
      ans += A.size() - i;
    }
  }
  return ans % 10003;
}

int main()
{
  string v1 = "AEX";
  int v2 = amazingSubarray(v1);
  cout << v2;

  return 0;
}
