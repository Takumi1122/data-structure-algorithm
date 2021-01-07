#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b;
  cin >> a >> b;
  if (a * b % 2 == 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}