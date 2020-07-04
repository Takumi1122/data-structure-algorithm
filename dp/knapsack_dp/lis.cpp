#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define MAX 100000
using namespace std;
using ll = long long;
using P = pair<int, int>;

// o(nlogn)

int n, A[MAX + 1], L[MAX];

int lis() {
  L[0] = A[0];
  int length = 1;

  for (int i = 1; i < n; i++) {
    if (L[length - 1] < A[i]) {
      L[length++] = A[i];
    } else {
      *lower_bound(L, L + length, A[i]) = A[i];
    }
  }

  return length;
}

int main() {
  cin >> n;
  rep(i, n) cin >> A[i];

  cout << lis() << endl;

  return 0;
}