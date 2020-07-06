#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 1-index bit[1]〜bit[n] o(log(N))

int N;
int bit[1000010];

// wを加える
void add(int a, int w) {
  for (int x = a; x <= N; x += x & -x) bit[x] += w;
}

// 和を求める
int sum(int a) {
  int ret = 0;
  for (int x = a; x > 0; x -= x & -x) ret += bit[x];
  return ret;
}