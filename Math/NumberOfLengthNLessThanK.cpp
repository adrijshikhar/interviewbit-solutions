#include <bits/stdc++.h>

using namespace std;

int titleToNumber(vector<int> &A, int B, int C) {
  vector<int> a;
  int c = 0;
  int n = A.size();

  // If the no of digit to be made is 1 then
  // check the no of digit present in array which are less than A
  if (B == 1) {
    for (auto x : A)
      if (x < C)
        c++;
    // The no digit can be made is equal to c
    return c;
  }

  // Push the C in a vector digit wise
  while (C > 0) {
    a.push_back(C % 10);
    C = C / 10;
  }

  // If the digit to be made is greater than C then return 0
  if (a.size() < B)
    return 0;
  else if (a.size() > B) {
    c = 0;
    for (auto x : A)
      if (x == 0)
        c++;
    // n-c guarantess there are no zero at begining
    // Rest position can be filled in n^b-1 ways
    return (n - c) * pow(n, B - 1);
  }

  // Reverse the digit where C is stored to get it in correct manner
  reverse(a.begin(), a.end());

  int d = 0;
  int k = 0;
  int r;
  int i;
  int l = 1;
  // Pick a digit from C
  for (auto x : a) {
    c = 0;
    l = 1;
    // Traverse over all the array Digit
    for (auto y : A)
      // Increment for all the digit between 1 to X
      if (y < x && (y != 0 || k > 0))
        c++;
      // Mark if it becomes equal
      else if (y == x)
        l = 2;

    // To get the ways for remaining element
    k++;
    r = 1;
    // B^n-K will be the remainign 4165
    for (i = 0; i < B - k; i++)
      r *= n;
    d += c * r;
    if (l == 1)
      break;
  }
  return d;
}

int main() {
  vector<int> v1{0, 1, 2, 5};
  int v2 = titleToNumber(v1, 2, 21);
  cout << v2 << " ";
  return 0;
}
