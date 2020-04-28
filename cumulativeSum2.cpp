#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];

  // 累積和と連想配列
  vector<long long> s(N + 1, 0);
  map<long long, long long> nums;
  for (int i = 0; i < N; ++i) s[i + 1] = s[i] + a[i];
  for (int i = 0; i < N + 1; ++i) nums[s[i]]++;

  // 集計処理
  long long res = 0;
  for (auto it : nums) {
    long long num = it.second;  // it.first が it.second 個ある
    res += num * (num - 1) / 2;
  }
  cout << res << endl;
}