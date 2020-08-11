#include <bits/stdc++.h>

using namespace std;

int findOverlappingPair(string str1, string str2, string &str) {
  // max will store maximum overlap i.e maximum
  // length of the matching prefix and suffix
  int max = INT_MIN;
  int len1 = str1.length();
  int len2 = str2.length();

  // check suffix of str1 matches with prefix of str2
  for (int i = 1; i <= min(len1, len2); i++) {
    // compare last i characters in str1 with first i
    // characters in str2
    if (str1.compare(len1 - i, i, str2, 0, i) == 0) {
      if (max < i) {
        // update max and str
        max = i;
        str = str1 + str2.substr(i);
      }
    }
  }

  // check prefix of str1 matches with suffix of str2
  for (int i = 1; i <= min(len1, len2); i++) {
    // compare first i characters in str1 with last i
    // characters in str2
    if (str1.compare(0, i, str2, len2 - i, i) == 0) {
      if (max < i) {
        // update max and str
        max = i;
        str = str2 + str1.substr(i);
      }
    }
  }

  return max;
}
int uniquePathsWithObstacles(vector<string> A) {
  int n = A.size(), ans = 0, k;

  // run len-1 times to consider every pair
    string resStr; // to store resultant string after
  while (n != 1) {
    int max = INT_MIN; // to store  maximum overlap
    int l, r;          // to store array index of strings
    // involved in maximum overlap
    // maximum overlap

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        string str;

        // res will store maximum ngth of the matching
        // prefix and suffix str is passed by reference and
        // will store the resultant string after maximum
        // overlap of arr[i] and arr[j], if any.
        int res = findOverlappingPair(A[i], A[j], str);

        // check for maximum overlap
        if (max < res) {
          max = res;
          resStr.assign(str);
          l = i, r = j;
        }
      }
    }

    n--; 
    if (max == INT_MIN)
      A[0] += A[n];
    else {
      A[l] = resStr;   // copy resultant string to index l
      A[r] = A[n]; // copy string at last index to index r
    }
  }

  return A[0].length();
}

int main() {
  vector<string> v{
      "cpsklryvmcp",
      "nbpbwllsrehfmx",
      "kecwitrsglre",
      "vtjmxypu",
  };
  int v2 = uniquePathsWithObstacles(v);

  cout << v2 << " ";

  return 0;
}
