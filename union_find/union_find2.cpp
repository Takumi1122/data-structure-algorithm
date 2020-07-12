#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

class DisjointSet {
 public:
  vector<int> rank, p;

  DisjointSet() {}
  DisjointSet(int size) {
    rank.resize(size, 0);
    p.resize(size, 0);
    rep(i, size) makeSet(i);
  }

  void makeSet(int x) {
    p[x] = x;
    rank[x] = 0;
  }

  bool same(int x, int y) { return findSet(x) == findSet(y); }

  void unite(int x, int y) { link(findSet(x), findSet(y)); }

  void link(int x, int y) {
    if (rank[x] > rank[y]) {
      p[y] = x;
    } else {
      p[x] = y;
      if (rank[x] == rank[y]) {
        rank[y]++;
      }
    }
  }

  int findSet(int x) {
    if (x != p[x]) {
      p[x] = findSet(p[x]);
    }
    return p[x];
  }
};

int main() {
  int n, a, b, q;
  int t;

  cin >> n >> q;
  DisjointSet ds = DisjointSet(n);

  rep(i, q) {
    cin >> t >> a >> b;
    if (t == 0)
      ds.unite(a, b);
    else if (t == 1) {
      if (ds.same(a, b))
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
  }

  return 0;
}