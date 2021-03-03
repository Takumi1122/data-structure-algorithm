#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int x, y;
  cin >> x >> y;
  set<int> st1{1, 3, 5, 7, 8, 10, 12};
  set<int> st2{4, 6, 9, 11};
  set<int> st3{2};

  if (st1.count(x) && st1.count(y)) {
    cout << "Yes" << endl;
    return 0;
  }
  if (st2.count(x) && st2.count(y)) {
    cout << "Yes" << endl;
    return 0;
  }
  if (st3.count(x) && st3.count(y)) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;

  return 0;
}