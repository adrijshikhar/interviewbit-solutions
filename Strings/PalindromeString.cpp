#include <bits/stdc++.h>

using namespace std;

int isPalindrome(string A)
{
  string B;
  for (int i = 0; i < A.size(); i++)
  {
    char ch = tolower(A[i]);
    int c = ch;
    if ((48 <= c && c <= 57) || (97 <= c && c <= 122))
    {
      B.push_back(char(ch));
    }
  }

  int n = B.size(), flag = 1;
  for (int i = 0; i < n / 2; i++)
  {
    if (B.at(i) != B.at(n - 1 - i))
    {
      flag = 0;
      break;
    }
  }

  return flag;
}

int main()
{
  string v1 = "A man, a plan, a canal: Panama";
  int v2 = isPalindrome(v1);
  cout << v2;

  return 0;
}
