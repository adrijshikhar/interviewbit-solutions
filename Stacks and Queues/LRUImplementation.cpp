#include <bits/stdc++.h>
using namespace std;

list<pair<int, int>> l;
int SZ;
map<int, list<pair<int, int>>::iterator> mp;

class LRUCache {
public:
  LRUCache(int capacity);
  int get(int key);
  void set(int key, int value);
};

LRUCache::LRUCache(int capacity) {
  l.clear();
  mp.clear();
  SZ = capacity;
}

int LRUCache::get(int key) {
  int val;
  if (mp.find(key) == mp.end())
    return -1;
  else {
    val = (mp[key])->second;
    l.erase(mp[key]);
    mp.erase(key);
    l.insert(l.begin(), {key, val});
    mp[key] = l.begin();

    return val;
  }
}

void LRUCache::set(int key, int value) {
  list<pair<int, int>>::iterator it;
  pair<int, int> kv;

  if (mp.find(key) != mp.end()) {
    l.erase(mp[key]);
    mp.erase(key);
  }

  if (l.size() == SZ) {
    kv = l.back();
    mp.erase(kv.first);
    l.pop_back();
  }

  l.insert(l.begin(), {key, value});
  mp[key] = l.begin();
}

int main() {

  LRUCache cache(2);
  cache.set(1, 10);
  cache.set(5, 12);
  cout << cache.get(5) << endl;
  cout << cache.get(1) << endl;
  cout << cache.get(10) << endl;
  cache.set(6, 14);
  cout << cache.get(5) << endl;
  return 0;
}
