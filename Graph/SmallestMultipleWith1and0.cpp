#include <bits/stdc++.h>

using namespace std;

int mod(string t, int N)
{
  int r = 0;
  for (int i = 0; i < t.size(); i++)
  {
    r = r * 10 + (t[i] - '0');
    r %= N;
  }
  return r;
}

string multiple(int A)
{
  string head = "1", fr;
  set<int> visit;
  queue<string> mq;
  mq.push(head);
  while (!mq.empty())
  {
    fr = mq.front();

    mq.pop();
    int rem = mod(fr, A);
    if (rem == 0)
      return fr;
    else if (visit.find(rem) == visit.end())
    {
      visit.insert(rem);
      mq.push(fr + "0");
      mq.push(fr + "1");
    }
    else
    {
      cout << rem << endl;
    }
  }
  return "";
}

int main()
{
  int v1 = 525;
  string v2 = multiple(v1);
  cout << v2;

  return 0;
}
