#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int nchoc(int A, vector<int> &B)
{
  long long int ans = 0, num;
  priority_queue<int> pq;

  for (int i = 0; i < B.size(); i++)
  {
    if (B[i] != 0)
    {
      B.push_back(B[i] / 2);
      pq.push(B[i]);
    }
  }

  int i = 0;
  while (i < A && !pq.empty())
  {
    num = pq.top();
    pq.pop();
    cout << num << " ";
    ans = (ans % MOD + num % MOD) % MOD;
    i++;
  }

  return ans;
}

int main()
{
  vector<int> v1{69, 61};
  int v2 = nchoc(34, v1);
  cout << v2 << " ";

  return 0;
}
