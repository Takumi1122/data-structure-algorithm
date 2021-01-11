#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  int n1 = 1 << n;
  vector<int> a(n1);
  rep(i, n1) cin >> a[i];

  map<int, int> mp;
  rep(i, n1) mp[a[i]] = i + 1;

  queue<int> q;
  rep(i, n1) q.push(a[i]);
  int ans = 0;
  while (q.size() > 1) {
    int x = q.front();
    q.pop();
    int y = q.front();
    q.pop();
    ans = min(x, y);
    q.push(max(x, y));
  }

  cout << mp[ans] << endl;
  return 0;
}