#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 蟻本P300: スライド最小値
// O(n)

template <class T>
vector<T> slide_min(const vector<T> &v, int k) {
  deque<int> deq;
  vector<T> ret;
  for (int i = 0; i < v.size(); i++) {
    while (!deq.empty() && v[deq.back()] >= v[i]) {
      deq.pop_back();
    }
    deq.push_back(i);
    if (i - k + 1 >= 0) {
      ret.emplace_back(v[deq.front()]);
      if (deq.front() == i - k + 1) deq.pop_front();
    }
  }
  return ret;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> b = slide_min<int>(a, k);

  rep(i, b.size()) cout << b[i] << endl;
}