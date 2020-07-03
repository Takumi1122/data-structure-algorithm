#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // 入力, キューにまずは順に要素を追加します
  int n;
  int q;  // クオンタム
  cin >> n >> q;
  queue<pair<string, int> > que;
  rep(i, n) {
    string name;
    int time;
    cin >> name >> time;
    que.push({name, time});
  }

  // ラウンドロビンスケジーリング
  int cur_time = 0;
  while (!que.empty()) {
    auto cur = que.front();
    que.pop();

    // Q 秒以上かかるとき、Q 秒処理してまたキューに追加
    if (cur.second > q) {
      cur_time += q;
      cur.second -= q;
      que.push(cur);
    }
    // Q 秒以内に終了するときは、処理を終えてプログラムを出力する
    else {
      cur_time += cur.second;
      cout << cur.first << " " << cur_time << endl;
    }
  }
}