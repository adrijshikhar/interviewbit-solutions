#include <bits/stdc++.h>

using namespace std;

vector<int> nextPermutation(vector<int> &v) {
  int i;
  for (i = v.size() - 2; i >= 0; i--) {
    if (v[i] < v[i + 1])
      break;
  }
  int j;
  int minim = INT_MAX;
  int index = -1;
  for (j = i + 1; j < v.size(); j++) {
    if (v[j] > v[i] && minim > v[j]) {
      index = j;
      minim = v[j];
    }
  }
  if (index != -1 && i != -1)
    swap(v[i], v[index]);
  sort(v.begin() + i + 1, v.end());
  return v;
}

int main() {
  vector<int> v1{34, 35, 27, 42, 5, 28, 39, 20, 28};
  vector<int> v2 = nextPermutation(v1);

  for (int i = 0; i < v2.size(); i++)
    cout << v2[i] << " ";

  return 0;
}
