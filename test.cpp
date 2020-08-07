#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  int temp = 0;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int area = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int condition = (int)area / n;
        if (condition < a[j]) {
          temp = (j - i) * (min(a[j], a[i]));
          if (temp > area) {
            area = temp;
          } else {
            continue;
          }
        }
      }
    }
    cout << area << endl;
  }
  return 0;
}
