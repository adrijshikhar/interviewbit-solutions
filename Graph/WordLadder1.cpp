
#include <bits/stdc++.h>
using namespace std;

int dpx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dpy[8] = {-2, 2, 1, -1, 2, -2, 1, -1};

bool checkOneChar(string A, string B)
{
  int flag = 0;
  for (int i = 0; i < A.size(); i++)
    if (A[i] != B[i])
      flag++;

  if (flag == 1)
    return true;
  else
    return false;
}
int wordLadder1(string A, string B, vector<string> &C)
{
  queue<string> myque;
  C.insert(C.begin(), A);
  C.push_back(B);
  unordered_map<string, int> path;
  int ans = 0;
  path[A] = 1;
  myque.push(A);
  while (!myque.empty())
  {
    string temp = myque.front();
    myque.pop();

    for (int i = 0; i < C.size(); i++)
    {
      string temp2 = C[i];
      if (checkOneChar(temp, temp2))
      {
        if (path.find(C[i]) == path.end())
        {
          myque.push(C[i]);
          path[C[i]] = path[temp] + 1;
        }
        else
        {
          if (path[temp] + 1 < path[C[i]])
            path[C[i]] = path[temp] + 1;
        }
      }
      else if (temp.compare(B) == 0)
        return path[temp];
    }
  }
  return ans;
}

int main()
{
  string A = "hit", B = "cog";
  vector<string> C{"hot", "dot", "dog", "lot", "log"};
  int v2 = wordLadder1(A, B, C);
  cout << v2;
  return 0;
}
