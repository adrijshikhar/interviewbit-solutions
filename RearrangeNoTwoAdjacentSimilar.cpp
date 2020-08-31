#include <bits/stdc++.h>
using namespace std;
#define pic pair<int, char>

void rearrangeString(string str) {
  int n = str.length();

  int count[26] = {0};
  for (int i = 0; i < n; i++)
    count[str[i] - 'a']++;

  priority_queue<pair<int, char>> pq;
  for (char c = 'a'; c <= 'z'; c++)
    if (count[c - 'a'])
      pq.push({count[c - 'a'], c});

  str = "";

  pic prev{-1, '#'};

  while (!pq.empty()) {

    pic k = pq.top();
    pq.pop();
    str = str + k.second;

    if (prev.first > 0)
      pq.push(prev);

    (k.first)--;
    prev = k;
  }

  if (n != str.length())
    cout << " Not valid String " << endl;

  else // valid string
    cout << str << endl;
}

// Driver program to test above function
int main() {
  string str = "bbbaacccc";
  rearrangeString(str);
  return 0;
}
