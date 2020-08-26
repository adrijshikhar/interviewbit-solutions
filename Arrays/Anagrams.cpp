#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> diagonal(const vector<string> &A) {
  int n = A.size();
  vector<int> len(n, 0);
  for (int i = 0; i < n; i++)
    len[i] = A[i].size();

  map<string, set<int>> mp;
  for (int i = 0; i < n; i++) {
    string str = A[i];
    sort(str.begin(), str.end());

    mp[str].insert(i + 1);
  }

  vector<vector<int>> ans;
  for (auto j : mp) {
    ans.push_back(vector<int>(j.second.begin(), j.second.end()));
  }
  return ans;
}

int main() {
  vector<string> v1{"cat", "dog", "god", "tca"};
  vector<vector<int>> v2 = diagonal(v1);
  for (auto i = 0; i < v2.size(); i++) {
    for (int j = 0; j < v2[i].size(); j++) {
      cout << v2[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
