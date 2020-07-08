#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<P>>;

const int MAX_V = 2100;  // ツリーのサイズのありうる最大値

int n;                    // ツリーのサイズ
vector<int> tree[MAX_V];  // ツリーを隣接リスト形式のグラフ構造で表したもの

int sizeSubtree[MAX_V];  // sizeSubtree[v] := v を根とする部分ツリーのサイズ
vector<int> centroids;  // 重心列挙の答えがここに入る

/* ツリーDP */
void subFindCentroids(int v, int parent_of_v = -1) {
  sizeSubtree[v] = 1;
  bool isCentroid = true;
  for (auto ch : tree[v]) {
    if (ch == parent_of_v) continue;
    subFindCentroids(ch, v);
    if (sizeSubtree[ch] > n / 2) isCentroid = false;
    sizeSubtree[v] += sizeSubtree[ch];
  }
  if (n - sizeSubtree[v] > n / 2) isCentroid = false;
  if (isCentroid) centroids.push_back(v);
}

void findCentroids() {
  centroids.clear();
  subFindCentroids(
      0, n);  // これを呼び出すと centoroids に重心を列挙したものが入る
}