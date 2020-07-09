#include <bits/stdc++.h>
#define mod 1000003;

using namespace std;

long long int fact(long long int A)
{
  return A <= 1 ? 1 : (A * (fact(A - 1)));
}

vector<int> getRow(int A)
{
  int n = A, r = 0;
  vector<int> B;
  int fN = fact(n);

  for (int i = 0; i <= A; i++)
  {
    long long int val = fN / (fact(i) * fact(A - i));
    B.push_back(val);
  }

  return B;
}

int main()
{
  int v1 = 3;
  vector<int> v2 = getRow(v1);
  for (auto i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }
  return 0;
}
