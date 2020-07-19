#include <bits/stdc++.h>

using namespace std;

string prevSmaller(string A)
{
  queue<char> q;
  string b;
  vector<int> charCount(26, 0);

  for (int i = 0; A[i]; i++)
  {
    q.push(A[i]);
    charCount[A[i] - 'a']++;
    while (!q.empty())
    {
      if (charCount[q.front() - 'a'] > 1)
        q.pop();
      else
      {
        b.push_back(q.front());
        break;
      }
    }

    if (q.empty())
      b.push_back('#');
  }
  return b;
}

int main()
{
  string v1 = "abcabc";
  string v2 = prevSmaller(v1);
  cout << v2 << " ";

  return 0;
}
