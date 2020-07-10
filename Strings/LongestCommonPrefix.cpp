#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string> &A)
{
  string B;
  string firstWord = A[0];
  int flag = 1;

  for (int i = 0; i < firstWord.size(); i++)
  {
    for (int j = 0; j < A.size(); j++)
    {
      string word = A[j];
      if (word.size() < i)
      {
        break;
      }
      if (firstWord[i] != word[i])
      {
        flag = 0;
        break;
      }
    }
    if (flag == 1)
    {
      B.push_back(firstWord[i]);
    }
  }

  return B;
}

int main()
{
  vector<string> v1{"ABCD"};
  string v2 = longestCommonPrefix(v1);
  cout << v2;

  return 0;
}
