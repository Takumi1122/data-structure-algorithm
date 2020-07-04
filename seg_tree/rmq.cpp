#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define INF 2147483647  // 2^31-1

vector<int> value;  // ノードの値を持つ配列
int N;              // 葉の数

void update(int i, int x) {
  // i 番目の葉の値を x に変える
  i += N - 1;  // i 番目の葉のノード番号
  value[i] = x;
  while (i > 0) {
    i = (i - 1) / 2;  // ノード i の親ノードの番号に変える
    value[i] = min(value[i * 2 + 1],
                   value[i * 2 + 2]);  // 左右の子の min を計算しなおす
  }
}

int query(int a, int b, int k, int l, int r) {
  // [a, b) の区間に対するクエリについて
  // ノード k （区間 [l, r) 担当）が答える
  if (r <= a || b <= l) return INF;  // 区間が被らない場合は INF を返す
  if (a <= l && r <= b)
    return value[k];  // ノード k の担当範囲がクエリ区間 [a, b)
                      // に完全に含まれる
  else {
    int c1 = query(a, b, 2 * k + 1, l, (l + r) / 2);  // 左の子に値を聞く
    int c2 = query(a, b, 2 * k + 2, (l + r) / 2, r);  // 右の子に値を聞く
    return min(c1, c2);  // 左右の子の値の min を取る
  }
}

int main(void) {
  int n, q;
  cin >> n >> q;
  N = 1;
  while (N < n) N *= 2;  // 葉の数を計算（n以上の最小の2冪数）

  value = vector<int>(2 * N - 1, INF);

  rep(j, q) {
    int c;
    cin >> c;
    if (c == 0) {
      // update(i, x)
      int i, x;
      cin >> i >> x;
      update(i, x);
    } else {
      // find(s, t)
      int s, t;
      cin >> s >> t;
      cout << query(s, t + 1, 0, 0, N) << endl;
    }
  }
  return 0;
}