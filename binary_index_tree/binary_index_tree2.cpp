#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 0-index bit[0]〜bit[n-1] o(log(N))

int N;
int bit[1000010];

// wを加える
void add(int a, int w) {
  for (int x = a; x < N; x |= x + 1) {
    bit[x] += w;
  }
}

// 和を求める
int sum(int a) {
  int ret = 0;
  for (int x = a - 1; x >= 0; x = (x & (x + 1)) - 1) {
    ret += bit[x];
  }
  return ret;
}