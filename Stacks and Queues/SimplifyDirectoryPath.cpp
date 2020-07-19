#include <bits/stdc++.h>

using namespace std;

string simplifyPath(string A)
{
  vector<string> collection;
  string pathName = "";

  A.push_back('/');

  for (auto i = 0; i < A.length(); ++i)
  {
    if (A[i] == '/')
    {
      if (pathName.size() == 0)
        continue;

      else if (pathName == "..")
      {
        if (collection.size() > 0)
          collection.pop_back();
      }
      else if (pathName != ".")
        collection.emplace_back(pathName);

      pathName.clear();
    }
    else
      pathName.push_back(A[i]);
  }

  if (collection.empty())
    return "/";

  A.clear();
  for (int j = 0; j < collection.size(); ++j)
    A.append("/" + collection[j]);

  return A;
}

int main()
{
  string v1 = "a/s/d/../f/s/";
  string v2 = simplifyPath(v1);
  cout << v2 << " ";

  return 0;
}
