#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  bool four = false;
  rep(i, n) {
    char s;
    cin >> s;
    if (s == 'Y') four = true;
  }
  if (four) {
    cout << "Four" << endl;
  } else {
    cout << "Three" << endl;
  }
  return 0;
}