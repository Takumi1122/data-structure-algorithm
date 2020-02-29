#include <iostream>
using namespace std;

const int INF = 10000000;  // 十分大きな値に

int n;
int a[11000];  // 最大 10000 個なので余裕を持って 11000 に

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  int res = INF;  // 十分大きな数に設定します
  for (int i = 0; i < n; i++) {
    if (res > a[i]) res = a[i];
  }

  cout << res << endl;
}