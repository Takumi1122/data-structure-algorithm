#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 「すべての株は買ってから1日で売る」

/*
    参考リンク
    M-SOLUTIONS プロコンオープン 2020 D - Road to Millionaire
      https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_d
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll money = 1000;
  rep(i, n - 1) {
    ll stocks = 0;
    if (a[i] < a[i + 1]) stocks = money / a[i];
    money += (a[i + 1] - a[i]) * stocks;
  }

  cout << money << endl;
  return 0;
}