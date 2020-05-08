#include <bits/stdc++.h>
using namespace std;

long long n, m, ans;
vector<long long> a;

//判定
bool chk(long long x) {
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    long long pos = lower_bound(a.begin(), a.end(), x - a[i]) - a.begin();
    cnt += (n - pos);
  }
  return cnt < m;  // X以上の和がM個未満かどうか
}

int main() {
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  //二分探索
  long long ng = 0, ok = LLONG_MAX;
  while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) / 2;
    if (chk(mid))
      ok = mid;
    else
      ng = mid;
  }
  //終了時にngにX-1,okにXが入っている。

  vector<long long> wa(n + 1);  // Aの累積和
  for (int i = 0; i < n; i++) wa[i + 1] = wa[i] + a[i];
  for (int i = 0; i < n; i++) {
    long long pos = upper_bound(a.begin(), a.end(), ng - a[i]) - a.begin();
    long long cnt = n - pos;
    ans += cnt * a[i] + (wa[n] - wa[pos]);
    m -= cnt;
  }
  ans += m * ng;
  cout << ans << endl;
}