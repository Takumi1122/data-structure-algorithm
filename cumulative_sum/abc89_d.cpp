#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// Dで割った余りを用いて累積和

/*
    1 <= A_i,j <= H*W
    A_i,j != A_x,y ((i,j) != (x,y))
    よって,各座標の整数は異なり,H*W以下となる
*/

/*
    参考リンク
    ABC 89 D - Practical Skill Test
      https://atcoder.jp/contests/abc089/tasks/abc089_d
*/

int px[100000], py[100000];
int dist[100000];

int main() {
  int h, w, d;
  cin >> h >> w >> d;
  rep(i, h) rep(j, w) {
    int a;
    cin >> a;
    px[a] = i;
    py[a] = j;
  }

  for (int i = d + 1; i < 100000; i++) {
    dist[i] = dist[i - d] + abs(px[i] - px[i - d]) + abs(py[i] - py[i - d]);
  }

  int q;
  cin >> q;
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    cout << dist[r] - dist[l] << endl;
  }
  return 0;
}