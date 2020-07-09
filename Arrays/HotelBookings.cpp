#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int K)
{
   vector<pair<int, int> > ans;
    for(int i =0; i<arrive.size(); i++) {
        ans.push_back(make_pair(arrive[i], 1));
        ans.push_back(make_pair(depart[i], 0));
    }
    
    sort(ans.begin(), ans.end());
    
    int curr = 0, max1 = 0;
    
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i].second == 1) {
            curr++;
            max1 = max(max1, curr);
        } else {
            curr--;
        }
    }
    return(K >= max1);
}

int main()
{
  vector<int> v1{36, 45, 41, 7, 3, 44, 40, 46, 3, 16, 24, 3, 8, 33};
  vector<int> v2{71, 73, 85, 8, 11, 62, 64, 76, 25, 65, 25, 30, 36, 81};
  int c = 14;
  bool v3 = hotel(v1, v2, c);
  cout << v3;

  return 0;
}
