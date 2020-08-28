#include <bits/stdc++.h>

using namespace std;

vector<int> graycode(int A) {
  vector<int> result(1, 0);
  for (int i = 0; i < A; i++) {
    int curSize = result.size();
    for (int j = curSize - 1; j >= 0; j--) {
      result.push_back(result[j] + (1 << i));
    }
  }
  return result;
}

int main() {
  int v1 = 10;
  vector<int> v2 = graycode(v1);

  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i] << " ";
  }

  return 0;
}
