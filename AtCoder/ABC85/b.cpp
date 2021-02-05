#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d[i];
  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  cout << d.size() << endl;
  return 0;
}