#include <bits/stdc++.h>

using namespace std;

vector<int> stepnum(int A, int B) {
  queue<int> q;
  vector<int> ans;
  if (A == 0)
    ans.push_back(0);
  for (int i = 1; i <= 9; i++) {
    if (i >= A && i <= B)
      ans.push_back(i);
    q.push(i);
  }

  while (!q.empty()) {
    int node = q.front();
    cout << node << " ";
    q.pop();
    int rem = node % 10;
    int num;
    if (rem - 1 >= 0) {
      num = node * 10 + rem - 1;
      if (num >= A && num <= B)
        ans.push_back(num);
      if (num <= B)
        q.push(num);
    }
    if (rem + 1 <= 9) {
      num = node * 10 + rem + 1;
      if (num >= A && num <= B)
        ans.push_back(num);
      if (num <= B)
        q.push(num);
    }
  }
  return ans;
}

int main() {
  int A = 10, B = 20;
  vector<int> v2 = stepnum(A, B);
  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i] << " ";
  }

  return 0;
}
