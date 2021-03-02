#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  int x1 = (double)n / 1.08;
  int x2 = ceil((double)n / 1.08);

  if (int(x1 * 1.08) == n) {
    cout << x1 << endl;
  } else if (int(x2 * 1.08) == n) {
    cout << x2 << endl;
  } else {
    cout << ":(" << endl;
  }
}