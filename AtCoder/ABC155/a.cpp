#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  set<int> s;
  s.insert(a);
  s.insert(b);
  s.insert(c);

  if (s.size() == 2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}