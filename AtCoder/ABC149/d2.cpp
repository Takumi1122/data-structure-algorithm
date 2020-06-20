#include <bits/stdc++.h>
using namespace std;

// r -> P, s -> R, p -> S
int main() {
  int N, K, R, S, P;
  string T;
  cin >> N >> K >> R >> S >> P >> T;
  auto score = [&](int i) {
    if (T[i] == 'r')
      return P;
    else if (T[i] == 's')
      return R;
    else
      return S;
  };
  long long res = 0;
  for (int k = 0; k < K; ++k) {
    bool last = false;
    for (int i = k; i < N; i += K) {
      if (i >= K && T[i - K] == T[i] && last)
        last = false;
      else
        res += score(i), last = true;
    }
  }
  cout << res << endl;
}