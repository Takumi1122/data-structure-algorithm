#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int A, B, C, K;
  bool flag = false;
  cin >> A >> B >> C >> K;

  for (int i = 0; i <= K; i++) {
    for (int j = 0; j <= K; j++) {
      for (int k = 0; k <= K; k++) {
        int x = A * (1 << i), y = B * (1 << j), z = C * (1 << k);
        if (i + j + k <= K && x < y && y < z) flag = true;
      }
    }
  }
  if (flag == true)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}