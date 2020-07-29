#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int A, B, C, K, cnt = 0;
  cin >> A >> B >> C >> K;
  while (A >= B) {
    cnt += 1;
    B *= 2;
  }
  while (B >= C) {
    cnt += 1;
    C *= 2;
  }
  if (cnt <= K)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}