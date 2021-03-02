#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 暗証番号は000~999なので、全部試す
// 暗証番号000~999が部分列（連続しないを含む）に含まれるかをO(n)で判定

/*
    参考リンク
    三井住友信託銀行プログラミングコンテスト2019 D - Lucky PIN
      https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
*/

int main() {
  int n;
  string s;
  cin >> n >> s;

  int ans = 0;
  rep(i, 1000) {
    string t;
    int x = i;
    rep(j, 3) {
      t += '0' + x % 10;
      x /= 10;
    }

    // 部分列（連続しないを含む）として含まれるかを判定 O(n)
    int ti = 0;
    rep(j, n) {
      if (s[j] == t[ti]) {
        ++ti;
        if (ti == 3) {
          break;
        }
      }
    }
    if (ti == 3) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}