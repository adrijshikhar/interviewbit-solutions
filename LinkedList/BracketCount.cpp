#include <bits/stdc++.h>

using namespace std;

bool ArePair(char opening, char closing)
{
  if (opening == '(' && closing == ')')
    return true;
  else if (opening == '{' && closing == '}')
    return true;
  else if (opening == '[' && closing == ']')
    return true;
  return false;
}
int isValid(string A)
{
  stack<char> s;
  string ans;
  int i = 0;
  while (i < A.size())
  {
    if (A[i] == '(' || A[i] == '{' || A[i] == '[')
    {
      s.push(A[i]);
    }
    else if (A[i] == ')' || A[i] == '}' || A[i] == ']')
    {
      if (s.empty() || !ArePair(s.top(), A[i]))
      {
        return 0;
      }
      else
      {
        s.pop();
      }
    }
    i++;
  }

  return s.empty();
}

int main()
{
  string v1 = "{){][(])";
  int v2 = isValid(v1);
  cout << v2;

  return 0;
}
