#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int popcnt(int x) {
  int cnt = 0;
  while (x) cnt += x & 1, x >>= 1;
  return cnt;
}