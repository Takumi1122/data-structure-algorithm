#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;  // 要素数
  vector<int> a;
  cin >> n;
  rep(i, n) {
    int a_temp;
    cin >> a_temp;
    a.push_back(a_temp);
  }

  sort(a.begin(), a.end());  // a を小さい順にソート

  // 出力
  rep(i, n) cout << a[i] << " ";
  cout << endl;
}