#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 119 C - Synthetic Kadomatsu
      https://atcoder.jp/contests/abc119/tasks/abc119_c
*/

void chmin(int &a, int b) {
  if (a > b) a = b;
}

const int INF = 1e9;
int N, A, B, C;
vector<int> L;

int rec(int i, int a, int b, int c) {
  if (i == N) {
    if (!a || !b || !c) return INF;
    // 合体してできたa,b,cをA,B,Cにするコスト
    return abs(a - A) + abs(b - B) + abs(c - C);
  }

  // 今ある竹を採用しない場合
  int res = rec(i + 1, a, b, c);

  // A,B,Cを使う場合
  // (a ? 10 : 0)は、最初の1本目は合体コストなし、2本目からはコスト10
  chmin(res, rec(i + 1, a + L[i], b, c) + (a ? 10 : 0));
  chmin(res, rec(i + 1, a, b + L[i], c) + (b ? 10 : 0));
  chmin(res, rec(i + 1, a, b, c + L[i]) + (c ? 10 : 0));

  return res;
}

int main() {
  cin >> N >> A >> B >> C;
  L.resize(N);
  rep(i, N) cin >> L[i];
  cout << rec(0, 0, 0, 0) << endl;
}