#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int ans = (N + 1) / 2;  // ceil(N/2) 切り上げ
  cout << ans << endl;
  return 0;
}