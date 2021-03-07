#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 長さmの区間にiが含まれているか

/*
    参考リンク
    ABC 194 E - Mex Min
      https://atcoder.jp/contests/abc194/tasks/abc194_e
*/

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> p(n);
  rep(i, n) {
    int a;
    cin >> a;
    p[a].push_back(i);
  }

  rep(i, n) {
    int pre = -1;
    p[i].push_back(n);
    for (int j : p[i]) {
      if (j - pre > m) {
        cout << i << endl;
        return 0;
      }
      pre = j;
    }
  }
  cout << n << endl;
  return 0;
}