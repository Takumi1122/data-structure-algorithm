#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define N 8
#define FREE -1
#define NOT_FREE 1

int row[N], col[N], dpos[2 * N - 1], dneg[2 * N - 1];

bool X[N][N];

void initialize() {
  rep(i, N) row[i] = FREE, col[i] = FREE;
  rep(i, 2 * N - 1) dpos[i] = FREE, dneg[i] = FREE;
}

void printBoard() {
  rep(i, N) rep(j, N) {
    if (X[i][j]) {
      if (row[i] != j) return;
    }
  }

  rep(i, N) {
    rep(j, N) { cout << ((row[i] == j) ? "Q" : "."); }
    cout << endl;
  }
}

void recursive(int i) {
  if (i == N) {
    // クイーンの配置に成功
    printBoard();
    return;
  }

  rep(j, N) {
    // (i, j)が他のクイーンに襲撃されている場合は無視
    if (NOT_FREE == col[j] || NOT_FREE == dpos[i + j] ||
        NOT_FREE == dneg[i - j + N - 1])
      continue;
    // (i, j)にクイーンを配置する
    row[i] = j;
    col[j] = dpos[i + j] = dneg[i - j + N - 1] = NOT_FREE;
    // 次の行を試す
    recursive(i + 1);
    // (i, j)に配置されているクイーンを取り除く
    row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = FREE;
  }
  // クイーンの配置に失敗
}

int main() {
  initialize();

  rep(i, N) rep(j, N) X[i][j] = false;

  int k;
  cin >> k;
  rep(i, k) {
    int r, c;
    cin >> r >> c;
    X[r][c] = true;
  }

  recursive(0);

  return 0;
}