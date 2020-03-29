#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k, n;
  cin >> k >> n;
  vector<int> A(n);
  rep(i, n) { cin >> A[i]; }
  sort(A.begin(), A.end());
  vector<int> D(n);
  rep(i, n) {
    if (i < n - 1) {
      D[i] = abs(A[i] - A[i + 1]);
    } else {
      D[i] = abs(A[i] - k) + A[0];
    }
  }
  sort(D.begin(), D.end());
  D.pop_back();
  int d = 0;
  int n1 = n - 1;
  rep(i, n1) { d += D[i]; }
  cout << d << endl;
  return 0;
}