#include <bits/stdc++.h>

using namespace std;

string reverseString(string A)
{
  stack<char> s;
  string ans;
  int i = 0;
  while (i < A.size())
  {
    s.push(A[i]);
    i++;
  }
  i = 0;
  while (i < A.size())
  {
    ans += s.top();
    s.pop();
    i++;
  }
  return ans;
}

int main()
{
  string v1 = "asdfasdf";
  string v2 = reverseString(v1);
  cout << v2;

  return 0;
}
