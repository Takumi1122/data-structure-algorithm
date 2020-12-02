#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 蟻本P49: Fence Repair

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i, n) cin >> l[i];

  ll ans = 0;
  priority_queue<int, vector<int>, greater<int>> que;
  rep(i, n) que.push(l[i]);

  while (que.size() > 1) {
    int min1, min2;
    min1 = que.top();
    que.pop();
    min2 = que.top();
    que.pop();

    ans += min1 + min2;
    que.push(min1 + min2);
  }

  cout << ans << endl;
  return 0;
}