#include <bits/stdc++.h>

using namespace std;

vector<int> nMaxPairCombinations(vector<int> &A, vector<int> &B)
{
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  vector<int> res;
  int N = A.size();

  priority_queue<pair<int, pair<int, int>>> pq;

  set<pair<int, int>> indices;

  pq.push(make_pair((A[N - 1] + B[N - 1]), make_pair(N - 1, N - 1)));
  indices.insert(make_pair(N - 1, N - 1));

  for (int count = 0; count < N; count++)
  {
    pair<int, pair<int, int>> temp = pq.top();
    pq.pop();
    res.push_back(temp.first);

    int i = temp.second.first;
    int j = temp.second.second;

    int sum = A[i - 1] + B[j];

    pair<int, int> tempIndex = make_pair(i - 1, j);

    if (indices.find(tempIndex) == indices.end())
    {
      pq.push(make_pair(sum, tempIndex));
      indices.insert(tempIndex);
    }

    sum = A[i] + B[j - 1];
    tempIndex = make_pair(i, j - 1);

    if (indices.find(tempIndex) == indices.end())
    {
      pq.push(make_pair(sum, tempIndex));
      indices.insert(tempIndex);
    }
  }
  return res;
}

int main()
{
  vector<int> v1{100, 4, 200, 1, 3, 2};
  vector<int> v2{71, 73, 85, 8, 11, 81};

  vector<int> v3 = nMaxPairCombinations(v1, v2);

  for (int i = 0; i < v3.size(); i++)
  {
    cout << v3[i] << ' ';
  }

  return 0;
}
