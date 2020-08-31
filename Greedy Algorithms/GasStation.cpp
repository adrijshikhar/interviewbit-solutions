#include <bits/stdc++.h>
using namespace std;
int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
  int sumGas = 0, sumCost = 0, start = 0, tank = 0;

  for (int i = 0; i < gas.size(); i++) {
    sumGas += gas[i];
    sumCost += cost[i];
    tank += gas[i] - cost[i];
    if (tank < 0) {
      start = i + 1;
      tank = 0;
    }
  }
  if (sumGas < sumCost) {
    return -1;
  } else {
    return start;
  }
}

int main() {
  vector<int> v1{2, 3, 2};
  vector<int> v3{2, 2, 3};

  int v2 = canCompleteCircuit(v1, v3);
  cout << v2;
  return 0;
}
