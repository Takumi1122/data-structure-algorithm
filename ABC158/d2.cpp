#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  deque<char> Q;
  for (char c : s) Q.push_back(c);
  bool flip = false;
  int q;
  cin >> q;
  rep(qi, q) {
    int ty;
    cin >> ty;
    if (ty == 1) {
      flip = !flip;
    } else {
      int f;
      char c;
      cin >> f >> c;
      if (f == 1) {
        Q.push_front(c);
      } else {
        Q.push_back(c);
      }
    }
  }
  if (flip) reverse(Q.begin(), Q.end());
  string ans;
  for (char c : Q) ans += c;
  cout << ans << endl;
  return 0;
}