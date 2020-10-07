#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// いもす法 O(n + t)

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_A
*/

typedef pair<int, int> Interval;  // means the interval [first, second)

// T: max value of intervals
int imos(const vector<Interval> &intervals, int T) {
  vector<int> nums(T + 1, 0);
  for (auto interval : intervals) {
    nums[interval.first]++;
    nums[interval.second]--;
  }
  for (int t = 0; t < T; ++t) {
    nums[t + 1] += nums[t];
  }
  int res = 0;
  for (int t = 0; t <= T; ++t) res = max(res, nums[t]);
  return res;
}

int main() {
  int n, t;
  cin >> n >> t;
  vector<Interval> intervals(n);
  rep(i, n) cin >> intervals[i].first >> intervals[i].second;
  cout << imos(intervals, t) << endl;
}