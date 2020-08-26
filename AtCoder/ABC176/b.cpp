#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string n;
  cin >> n;
  ll sum = 0;
  rep(i, n.size()) {
    int n1 = n[i] - '0';
    sum += n1;
  }
  if (sum % 9 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}