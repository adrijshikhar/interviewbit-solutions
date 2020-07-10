#include <bits/stdc++.h>
#define mod 1000000007;
typedef long long int ll;

using namespace std;

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll findlcm(vector<ll> arr)
{
  ll ans = arr[0];
  for (int i = 1; i < arr.size(); i++)
  {
    cout << ans << endl;
    ans = (((arr[i] * ans)) /
           (gcd(arr[i], ans))) %
          mod;
  }

  return ans  ;
}

ll calculateTime(string A)
{
  ll t = 0, i = 0, s = A.size();
  string word = A;
  while (true)
  {
    t++;
    word = word.substr(i + 1, s - i) + word.substr(0, i + 1);
    i = (i + 1) % s;
    if (word == A)
    {
      return t % mod;
    }
  }

  return t % mod;
}
int amazingSubarray(vector<string> &A)
{
  ll s = A.size(), ans = 0;
  vector<ll> B(s, 0);
  for (int i = 0; i < s; i++)
  {
    int t = calculateTime(A[i]);
    B[i] = t;
  }
  for (int j = 0; j < B.size(); j++)
  {
    cout << B[j] << " ";
  }

  ans = findlcm(B);
  return ans % mod;
}

int main()
{
  vector<string> v1{"bbababbbaabbaaabbbab", "baabaaaabbbbaabbbaaabbabbbabbaaaaaaabaaababbaa", "aababaaaabbbabbabbabaabbabababaabbabaabababbbabababaabbaabaaaa", "aaabaaaabbbaababaaaaabbbabbabbbbbbababbbaaaababaaaaababbbaaaa", "abaababaabbaaaabaabbabbaaaaaaabaaabbaabaaaaababbabababbabbba", "aaaabbbaababaaaabbbaaaabbbbaabaababbbababbbbbbaaabb", "b", "aaabaaabbbbaababbbaabbbbabababaabbbbbbaaaaab", "aaaabababaaaababaaabbbaaabbababaababbbaabaababaababbbbbbaabaaaabbaaaba", "abbbbabbbbaaabaaaababaaabaaabbabababbbabaababbabaabbabbbbbbaaababbbbabaabbbbbbabbaabbbbbaab", "abbaabbbabbaaabbababbabbbaaaabbbaabbbaaabbababbaabbaaabbabbbaaabbbaabaaababbbabaabaabbba", "bbabbbaabbbbbbbaaabba", "bbbbaaaaabbbbaabaaabbaaaabbbabbbaaaa", "abbaaabbbabbbbabbbbaaa", "bbbbabbbaaaabbbaabbbaabbaaaaabbbaaaaaabaaaabbbbbababbbababaaabaabab", "aabbababaaabbaaaaaaabaabbaaabbabbbaabbbbbaaaaaaabaaaababbaaabaaabaaabaaaaaaabbbabbaaaabaababbaabbaba", "bbaab", "baababbaaabaabaaababaabababbababbaabaabaabaaaaaabaabbbaabbbaaabaaaba", "baaaaaabbaabaaabaab", "abaaaaaabbaabaaabababbbbbabbaababbabbbaaaabbbbbaaaabababbbbabaaabbaaaaaaabbbbbbbbbabbabaaaabababaaba", "baabbaaabbabbbabaababbaabbabaabaabbbbbabaaabbaaaaaabbbbaabbbbabbbabbbbabbaaaaaaaabababbababaa", "aaabbbababbabbbab", "bbbbbababbabbabababbbaaaaa", "babbbaaababbbaabaaaaabbbababaaabababaabbbababbbbbabbbabbabaabbbbaaaaabab", "baaabbbbabab", "abbab", "babaababaaabbaababbbaaa", "aaababbabaaababbbbaaaaaaabbabbbbbbaaababbabaaabbabaa", "aaabbaabbbaabaaaabbabbbbaabbabbabbbbbbaaaaabbabba", "abbbabbab", "baabaaabbaaaaabbbbbbbbabaaababbaaab", "abbbbbbbabbbaaabbaabababaabaaaaabababbbbaaaaa", "bbaaabbbabbbabbabaaaaabbbbaabaababbaaabababbbaaaaabaaabaababaaa", "bbabbabbaaaaaaaabbabaababbbbaabbbabbaaaabaabbbaaaabaabaaaabaababbbabbababaaabaabababaabbaab", "bbaaaababbaabaaaaabbbbaaabbababbabbabbaaababbabaaabaabaaababbbabaaaab", "abbbabbbbabaabbabbbaaabbaabaaaa", "babbbbaabbabbbbaaaaaaabaaaaaaba", "baaabaaaaabbbabbaabaabbabbaaaabbaabbabbababaabbabbbbaabbbbbabbbabbbbabaabbaaaaab", "babbbabaababaaabbbaabaabaabaabbababbbabbbbaababbbbbbbb", "abbaaaaaaabbbaaabaabbabaaaababbabaabbab", "baaaaabaabbaaaaababbaabbababababbababaabab", "aaaababaabbbbabbaabbaababbaabbabbabaaaabbbabaaaaabaabbaa", "abaabbbbbabbaababaabaabba", "bbababaabbbaaaaaababbbbbabbaaaabbabbbbbabbbbbbbbaaabbbaaaaabaaababbabaaabbbbbbabbbbaa", "abbaabaabbaabbabbabababbbaaabbababaabaaabaaabaaaabbbbababbbaabbaabababbbbbabaababaaabbaa", "bababbbbaabbaaababbababbababaabbaaaaabbababbabbbbabaa", "baaabaababbabbbabaaaaaabbbbbbaaaaaaabbbbaabbaabbabaababbbbaabaababbbaaaabbbbbaaabaaaaabbbbba", "ababbbbbabababbaabbabbbbbaaaaaaa", "abbbaabbbbbaababababaaaaababbabbbaabaaabb", "abaaaabaabaaabbaaabbbabaabaabbabaababbababbaabbababbaababbbaabbabb", "aaababbbbaabbaaaaabbaaaaabaaababbbababaababbaabbabaab", "babbababababaaabaab", "baaababbbbbababbbbaaaababbbbbbbabbbaa", "bbbabaaaabbabbbabaabbbabababbababbaabaabbbababbabbbabbbbaaababbaabaabbbaabbba", "bbaaabbbabbaaaabaaaaabbababbbaaabaababbaaabaabbabbbaaaabababbabbbbababbaaaaabbbbaabaab", "baaaabababbbabaabbbbaaabbaabbbbaaaaababbaaaabaaabbaaaabbbaaabaabaabbbaabbabaabbabbabbbaabaabaaa", "babaabbbbaaabbaaaabbb", "abaaaa", "abaaaabababbababbbbbabbabaabaaaababaaaabababbbaaaaaabbaababbbabaaaabaa", "bababaabaabababbbbbaababbabababaaaabaaaabaaaabaabbabaaabbaaaabaababbabbbbba", "baaababbbaaaaaa", "baaaabbaaaaaaaabaabbaaabaababbaababbbaaabaabaaaaabbabbaabbaabbbabaabaabbabaabaa", "bbbbabbbbbaaabaababbaababbaaaa", "bbaababbbbbbbabbbaaaaabbbbbbba", "abbbbbaaabbbbbaaaababbaabbbaabbabababaabbbaaaababaaabaaabbbbbaaaababbaabbabbaab", "abbaababbbbabbabaaaaaabbaaabbbabaababaaabbabaaaaabaabbbaabbb", "babbabbabbbaaaaabbbabbbbbbbaaabaaababaabaabaaaabbbbabbbaaaababbbbabbbaababbabbaabbbaaaa", "baabababbaaaaabaaaabaaababbabbbabbabaabaabaaaaaaabbabbbbaaaabbab", "aabbbbbbaabaabababbaaaabaaaabbbbaaabaaaaabaaaaabbbbabbbaab", "bbbabbbabbbbbabbbabababbaaa", "aaabbbaaabaaabbbababbabaaaaaaaabaaabbab", "baabbbabababbbabb", "aaaabbbbaaaaabaabba", "baababbabaabaabb", "ababbabaaabbabaabaabbaabababababaaababaabbabaaaaaabbbbbbabaaabbbbbaa", "aaaaaaabaababbbaababbbbaaa", "aba", "babbbbaababaaabaaabbaabaabaaaababbbaabaaabaa", "baaabaabbaaababbababaabaabaabaabaabaabbbbbaaabaaaababaabaabbabababbaaaaaaaa", "baabbbbababbabbbabaabbbbbbbbbabaabbbaabaabbbaaaaaabbb", "aabaaaabaabbabbbbaabbabbbbbaaaababbabbabbbababbabbbaaabbaabaabbbaabbbbabaaabbbb", "babbabaabb"};
  int v2 = amazingSubarray(v1);
  cout << v2;

  return 0;
}
