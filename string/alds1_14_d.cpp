#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_D
*/

// Sparse Table
template <class MeetSemiLattice>
struct SparseTable {
  vector<vector<MeetSemiLattice> > dat;
  vector<int> height;

  SparseTable() {}
  SparseTable(const vector<MeetSemiLattice> &vec) { init(vec); }
  void init(const vector<MeetSemiLattice> &vec) {
    int n = (int)vec.size(), h = 0;
    while ((1 << h) < n) ++h;
    dat.assign(h, vector<MeetSemiLattice>(1 << h));
    height.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) height[i] = height[i >> 1] + 1;
    for (int i = 0; i < n; ++i) dat[0][i] = vec[i];
    for (int i = 1; i < h; ++i)
      for (int j = 0; j < n; ++j)
        dat[i][j] =
            min(dat[i - 1][j], dat[i - 1][min(j + (1 << (i - 1)), n - 1)]);
  }

  MeetSemiLattice get(int a, int b) {
    return min(dat[height[b - a]][a],
               dat[height[b - a]][b - (1 << height[b - a])]);
  }
};

// Suffix Array ( Manber&Myers: O(n (logn)^2) )
struct SuffixArray {
  string str;
  vector<int> sa;   // sa[i] : the starting index of the i-th smallest
                    // suffix (i = 0, 1, ..., n)
  vector<int> lcp;  // lcp[i]: the lcp of sa[i] and sa[i+1] (i = 0, 1, ..., n-1)
  inline int &operator[](int i) { return sa[i]; }

  SuffixArray(const string &str_) : str(str_) {
    buildSA();
    calcLCP();
  }
  void init(const string &str_) {
    str = str_;
    buildSA();
    calcLCP();
  }

  // build SA
  vector<int> rank_sa, tmp_rank_sa;
  struct CompareSA {
    int n, k;
    const vector<int> &rank;

    CompareSA(int n, int k, const vector<int> &rank_sa)
        : n(n), k(k), rank(rank_sa) {}

    bool operator()(int i, int j) {
      if (rank[i] != rank[j])
        return (rank[i] < rank[j]);
      else {
        int rank_ik = (i + k <= n ? rank[i + k] : -1);
        int rank_jk = (j + k <= n ? rank[j + k] : -1);
        return (rank_ik < rank_jk);
      }
    }
  };
  void buildSA() {
    int n = (int)str.size();
    sa.resize(n + 1), lcp.resize(n + 1), rank_sa.resize(n + 1),
        tmp_rank_sa.resize(n + 1);

    // 最初は1文字、ランクは文字コードにする
    for (int i = 0; i < n; ++i) sa[i] = i, rank_sa[i] = (int)str[i];
    sa[n] = n, rank_sa[n] = -1;

    // k文字についてソートされているところから、2k文字でソートする
    for (int k = 1; k <= n; k *= 2) {
      CompareSA csa(n, k, rank_sa);
      sort(sa.begin(), sa.end(), csa);

      tmp_rank_sa[sa[0]] = 0;
      for (int i = 1; i <= n; ++i) {
        tmp_rank_sa[sa[i]] = tmp_rank_sa[sa[i - 1]];
        if (csa(sa[i - 1], sa[i])) ++tmp_rank_sa[sa[i]];
      }
      for (int i = 0; i <= n; ++i) rank_sa[i] = tmp_rank_sa[i];
    }
  }

  vector<int> rsa;
  SparseTable<int> st;
  void calcLCP() {
    int n = (int)str.size();
    rsa.resize(n + 1);
    for (int i = 0; i <= n; ++i) rsa[sa[i]] = i;
    lcp.resize(n + 1);
    lcp[0] = 0;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      int pi = sa[rsa[i] - 1];
      if (cur > 0) --cur;
      for (; pi + cur < n && i + cur < n; ++cur) {
        if (str[pi + cur] != str[i + cur]) break;
      }
      lcp[rsa[i] - 1] = cur;
    }
    st.init(lcp);
  }

  // calc lcp
  int getLCP(int a, int b) {  // lcp of str.sutstr(a) and str.substr(b)
    return st.get(min(rsa[a], rsa[b]), max(rsa[a], rsa[b]));
  }

  // O(|t|log|str|)
  bool contains(string t) {
    int l = 0;
    int r = str.size();
    while (r - l > 1) {
      int mid = l + (r - l) / 2;
      int index = sa[mid];

      // 一致した場合には0が返されます。
      // 不一致が発生した場合には正の値または負の値が返されます。
      // 自身のほうが大きい場合は正の数
      // 自身のほうが小さい場合は負の数
      int cmp = str.compare(index, t.size(), t);
      if (cmp < 0)
        l = mid;
      else
        r = mid;
    }
    return str.compare(sa[r], t.size(), t) == 0;
  }
};

int main() {
  string t;
  int q;
  cin >> t >> q;

  // Suffix Array 構築
  SuffixArray SA(t);

  rep(i, q) {
    string p;
    cin >> p;
    cout << SA.contains(p) << endl;
  }
}