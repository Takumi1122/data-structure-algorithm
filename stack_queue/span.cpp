#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 100000000;  // 十分大きい値

// o(n)

int main() {
  // 入力
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  // スタック
  stack<pair<int, int> > st;
  st.push({INF, 0});  // 番兵
  rep(i, n) {
    // 条件を満たすまで pop し続ける
    while (a[i] > st.top().first) st.pop();

    // 答えを出力
    cout << st.top().second << ", ";

    // 新たに push
    st.push({a[i], i + 1});
  }
  cout << endl;
}