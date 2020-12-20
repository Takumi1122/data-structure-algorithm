#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// X以下の整数のXOR和
// => Xが奇数のときは,(X+1)/2が偶数なら0,奇数なら1
// => Xが偶数のときは,X+1が奇数なのでその答えからX+1を引く

// XOR の世界では「足し算」も「引き算」も(^)
// 2k^(2k+1) = 1

/*
    参考リンク
    ABC 121 D - XOR World
      https://atcoder.jp/contests/abc121/tasks/abc121_d
*/

ll oddsolve(ll a) { return (a + 1) / 2 % 2; }
ll solve(ll a) {
  if (a % 2 == 1)
    return oddsolve(a);
  else
    return oddsolve(a + 1) ^ (a + 1);
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << (solve(b) ^ solve(a - 1)) << endl;
}