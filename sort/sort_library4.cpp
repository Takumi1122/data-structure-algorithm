#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool cmp(int a, int b) { return abs(a - 50) < abs(b - 50); }

int main() {
  int n;  // 要素数
  vector<int> a;
  cin >> n;
  rep(i, n) {
    int a_temp;
    cin >> a_temp;
    a.push_back(a_temp);
  }

  sort(a.begin(), a.end(), cmp);  // 50 と近い順にソート

  // 出力
  rep(i, n) cout << a[i] << " ";
  cout << endl;
}