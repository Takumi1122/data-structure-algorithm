#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> f(h);
  rep(i, h) cin >> f[i];
  vector<vector<ll>> nums(h, vector<ll>(w, 0));

  rep(i, h) rep(j, w) {
    if (f[i][j] == '.') {
      nums[rec.first.first][rec.first.second]++;
      nums[rec.first.first][rec.second.second]--;
      nums[rec.second.first][rec.first.second]--;
      nums[rec.second.first][rec.second.second]++;
    }
  }
  return 0;
}