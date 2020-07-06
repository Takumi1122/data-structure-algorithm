#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

template <class Abel>
struct BIT {
  vector<Abel> dat;
  Abel UNITY_SUM = 0;  // to be set

  /* [1, n] */
  BIT(int n) { init(n); }
  void init(int n) {
    dat.resize(n + 1);
    for (int i = 0; i < (int)dat.size(); ++i) dat[i] = UNITY_SUM;
  }

  /* a is 1-indexed */
  inline void add(int a, Abel x) {
    for (int i = a; i < (int)dat.size(); i += i & -i) dat[i] = dat[i] + x;
  }

  /* [1, a], a is 1-indexed */
  inline Abel sum(int a) {
    Abel res = UNITY_SUM;
    for (int i = a; i > 0; i -= i & -i) res = res + dat[i];
    return res;
  }

  /* [a, b), a and b are 1-indexed */
  inline Abel sum(int a, int b) { return sum(b - 1) - sum(a - 1); }

  /* k-th number (k is 0-indexed) */
  int get(long long k) {
    ++k;
    int res = 0;
    int N = 1;
    while (N < (int)dat.size()) N *= 2;
    for (int i = N / 2; i > 0; i /= 2) {
      if (res + i < (int)dat.size() && dat[res + i] < k) {
        k = k - dat[res + i];
        res = res + i;
      }
    }
    return res + 1;
  }
};

int main() {
  int max_q = 210000;
  BIT<int> bit(max_q);
  int q, k;
  cin >> q >> k;
  vector<int> t(q);
  vector<ll> v(q);

  // クエリ先読み
  vector<ll> queries;
  rep(i, q) {
    cin >> t[i];
    if (t[i] == 1) cin >> v[i], queries.push_back(v[i]);
  }

  // 座標圧縮
  sort(queries.begin(), queries.end());
  queries.erase(unique(queries.begin(), queries.end()), queries.end());

  // クエリに答える
  rep(i, q) {
    if (t[i] == 1) {
      int index =
          lower_bound(queries.begin(), queries.end(), v[i]) - queries.begin();
      ++index;            // 1-index にする
      bit.add(index, 1);  // insert index
    } else {
      int size = bit.sum(max_q);  // insert されている全要素数
      if (k > size) {
        cout << -1 << endl;
      } else {
        int val = bit.get(k - 1);  // k-th number (original K is 1-indexed)
        cout << queries[val - 1] << endl;  // val を 0-indexed にする
        bit.add(val, -1);                  // erase val
      }
    }
  }
}