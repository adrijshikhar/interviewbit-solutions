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
 
  }
  return "";
}
 // approach 2
string multiple2(int A)
{
  queue<int> q;
  int rem = 1 % A;

  q.push(rem);
  vector<int> vis(A + 1, -1);
  vis[rem] = 1;
  vector<pair<int, char>> par(A + 1, {-1, '1'});
  while (!q.empty())
  {
    int tp = q.front();
    q.pop();

    if (tp == 0)
    {
      string s = "";

      s += par[0].second;
      int p = par[0].first;
      while (p != -1)
      {
        s += par[p].second;
        p = par[p].first;
      }

      reverse(s.begin(), s.end());

      return s;
    }

    int a1 = (tp * 10) % A;
    int a2 = ((tp * 10) % A + 1) % A;
    if (vis[a1] == -1)
    {

      q.push(a1);
      vis[a1] = 1;
      par[a1] = {tp, '0'};
    }

    if (vis[a2] == -1)
    {
      q.push(a2);
      vis[a2] = 1;
      par[a2] = {tp, '1'};
    }
  }
  return "";
}

int main()
{
  int v1 = 2;
  string v2 = multiple2(v1);
  cout << v2;

  return 0;
}
