#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> ans;
  rep(i, n) {
    int a;
    cin >> a;
    if (a != x) ans.push_back(a);
  }

  if (ans.size() == 0) {
    cout << " " << endl;
  } else {
    rep(i, ans.size()) cout << ans[i] << endl;
  }
  return 0;
}