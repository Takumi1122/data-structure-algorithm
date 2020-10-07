#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// いもす法 2次元
// O(n + xy)

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_B
*/

const int MAX_X = 1001;
const int MAX_Y = 1001;

using Point = pair<int, int>;
using Rectangle = pair<Point, Point>;

int imos(const vector<Rectangle> &recs) {
  vector<vector<int> > nums(MAX_X + 1, vector<int>(MAX_Y + 1, 0));

  for (auto rec : recs) {
    nums[rec.first.first][rec.first.second]++;
    nums[rec.first.first][rec.second.second]--;
    nums[rec.second.first][rec.first.second]--;
    nums[rec.second.first][rec.second.second]++;
  }
  rep(x, MAX_X) rep(y, MAX_Y) nums[x][y + 1] += nums[x][y];
  rep(y, MAX_Y) rep(x, MAX_X) nums[x + 1][y] += nums[x][y];

  int res = 0;
  for (int x = 0; x <= MAX_X; ++x)
    for (int y = 0; y <= MAX_Y; ++y) res = max(res, nums[x][y]);
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<Rectangle> recs(n);
  rep(i, n) cin >> recs[i].first.first >> recs[i].first.second >>
      recs[i].second.first >> recs[i].second.second;
  cout << imos(recs) << endl;
}