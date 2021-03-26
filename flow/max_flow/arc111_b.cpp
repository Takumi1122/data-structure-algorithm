#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// O(min(n^(2/3)*m, m^(3/2))) (辺の容量がすべて1の時)
// n:6 * 10^5  m:4 * 10^5 でもいけた

/*
    参考リンク
    ARC 111 B - Reversible Cards
      https://atcoder.jp/contests/arc111/tasks/arc111_b
*/

const int numNode = 2 * 100000;
const int numColor = 4 * 100000;
const int numGraph = numNode + numColor + 100;
const int snode = numGraph - 3;
const int tnode = numGraph - 2;

int main() {
  int n;
  cin >> n;
  mf_graph<int> mf(numGraph);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    mf.add_edge(snode, i, 1);
    mf.add_edge(i, a + numNode, 1);
    mf.add_edge(i, b + numNode, 1);
  }

  rep(i, numColor) mf.add_edge(i + numNode, tnode, 1);

  cout << mf.flow(snode, tnode) << endl;
  return 0;
}