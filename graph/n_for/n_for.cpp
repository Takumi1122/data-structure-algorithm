#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// n重for文
// 0000000000 ~ 1111111111

/*
    // 実装テンプレ
    ・長さNの数列を生成したい
    ・数列の各項の値は0,1,…,M−1であるようにしたい
    ・計算量 : O(M^N)
*/

const int M = 2;
void dfs(vector<int> &A) {
  // 終端条件 --- 10 重ループまで回したら処理して打ち切り
  // 数列の長さを決める
  if (A.size() == 10) {
    for (int i = 0; i < 10; ++i) cout << A[i];
    cout << endl;
    return;
  }

  for (int v = 0; v < M; ++v) {
    A.push_back(v);
    dfs(A);
    A.pop_back();  // これが結構ポイント
  }
}

int main() {
  vector<int> A;
  dfs(A);
}