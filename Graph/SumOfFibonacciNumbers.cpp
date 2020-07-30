#include <bits/stdc++.h>

using namespace std;

int fibsum(int A)
{
  vector<int> fiboTerms;

  int i = 3, nextTerm;
  fiboTerms.push_back(0);
  fiboTerms.push_back(1);
  fiboTerms.push_back(1);

  while (1)
  {
    nextTerm = fiboTerms[i - 1] + fiboTerms[i - 2];
    if (nextTerm > A)
      break;

    fiboTerms.push_back(nextTerm);
    i++;
  }

  int count = 0, j = fiboTerms.size() - 1;

  while (A > 0)
  {
    count += (A / fiboTerms[j]);
    A %= (fiboTerms[j]);

    j--;
  }

  return count;
}

int main()
{
  int v1 = 10;
  int v2 = fibsum(v1);
  cout << v2;

  return 0;
}
