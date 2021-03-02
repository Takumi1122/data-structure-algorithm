#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 67 D - Fennec VS. Snuke
      https://atcoder.jp/contests/abc067/tasks/arc078_b
*/

int main() {
  int n;
  cin >> n;

  Graph G(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> dist1(n, -1);
  queue<int> que1;
  dist1[0] = 0;
  que1.push(0);
  while (!que1.empty()) {
    int v = que1.front();
    que1.pop();

    for (int nv : G[v]) {
      if (dist1[nv] != -1) continue;
      dist1[nv] = dist1[v] + 1;
      que1.push(nv);
    }
  }

  vector<int> dist2(n, -1);
  queue<int> que2;
  dist2[n - 1] = 0;
  que2.push(n - 1);
  while (!que2.empty()) {
    int v = que2.front();
    que2.pop();

    for (int nv : G[v]) {
      if (dist2[nv] != -1) continue;
      dist2[nv] = dist2[v] + 1;
      que2.push(nv);
    }
  }

  int cntf = 0;
  int cnts = 0;
  rep(i, n) {
    if (dist1[i] < dist2[i])
      cntf += 1;
    else if (dist1[i] == dist2[i])
      cntf += 1;
    else
      cnts += 1;
  }

  if (cnts > cntf || cnts == cntf) {
    cout << "Snuke" << endl;
  } else {
    cout << "Fennec" << endl;
  }
  return 0;
}