#include <bits/stdc++.h>

using namespace std;

char valChar(int n)
{
  char ch;

  if (1 <= n)
  {
    ch = 'I';
  }
  if (5 <= n)
  {
    ch = 'V';
  }
  if (10 <= n)
  {
    ch = 'X';
  }
  if (50 <= n)
  {
    ch = 'L';
  }
  if (100 <= n)
  {
    ch = 'C';
  }
  if (500 <= n)
  {
    ch = 'D';
  }
  if (1000 <= n)
  {
    ch = 'M';
  }

  return ch;
}

string intToRoman(int A)
{
  int B = A, power = 1, place = 1, parsedVal;
  string ans;

  while (B > 0)
  {
    string romanChar;
    parsedVal = B % int(pow(10, power));
    char ch = valChar(parsedVal * int(pow(10, power - 1)));

    if (parsedVal <= 5)
    {
      if (parsedVal == 4)
      {
        char chA = valChar((parsedVal + 1) * int(pow(10, power - 1)));
        char chB = valChar(int(pow(10, power - 1)));
        romanChar.push_back(chA);
        romanChar.push_back(chB);
        ans.append(romanChar);
        romanChar.clear();
      }
      else
      {

        int charLimit = parsedVal % 5;
        if (charLimit == 0)
        {
          ans.push_back(ch);
        }
        else
        {
          for (int i = 0; i < charLimit; i++)
          {
            romanChar.push_back(ch);
          }
          ans.append(romanChar);
        }
      }
    }
    else
    {
      int parsedVal2 = parsedVal - 5;
      if (parsedVal2 == 4)
      {
        char ch2A = valChar((parsedVal + 1) * int(pow(10, power - 1)));
        char ch2B = valChar(int(pow(10, power - 1)));
        romanChar.push_back(ch2A);
        romanChar.push_back(ch2B);
        ans.append(romanChar);
        romanChar.clear();
      }
      else
      {
        romanChar.push_back(ch);
        char ch2 = valChar(parsedVal2 * int(pow(10, power - 1)));
        for (int i = 0; i < parsedVal2; i++)
        {
          romanChar.push_back(ch2);
        }
        reverse(romanChar.begin(), romanChar.end());

        ans.append(romanChar);
      }
    }

    romanChar.clear();
    B = B / 10;
    power++;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  int v1 = 10;
  string v2 = intToRoman(v1);
  cout << v2;

  return 0;
}
