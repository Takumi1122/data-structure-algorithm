#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

bool is_integer(double x) { return floor(x) == x; }

int main() {
  string a, b;
  cin >> a >> b;

  string ab = a + b;
  double num = stoi(ab);

  if (is_integer(sqrt(num))) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}