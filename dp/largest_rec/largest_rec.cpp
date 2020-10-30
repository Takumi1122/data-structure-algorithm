#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 最大長方形(Largest Rectangle) O(H * W)

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_B
*/

struct Rectangle {
  int height;
  int pos;
};

int getLargestRectangle(int size, vector<int> t) {
  // まだ拡張される可能性のある長方形の情報を記録　
  stack<Rectangle> S;
  int maxv = 0;
  t.push_back(0);

  for (int i = 0; i <= size; i++) {
    Rectangle rect;
    rect.height = t[i];
    rect.pos = i;

    if (S.empty()) {
      S.push(rect);
    } else {
      if (S.top().height < rect.height) {
        S.push(rect);
      } else if (S.top().height > rect.height) {
        int target = i;
        while (!S.empty() && S.top().height >= rect.height) {
          Rectangle pre = S.top();
          S.pop();
          int area = pre.height * (i - pre.pos);
          maxv = max(maxv, area);
          target = pre.pos;
        }
        rect.pos = target;
        S.push(rect);
      }
    }
  }
  return maxv;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> c(h, vector<int>(w, 0));
  vector<vector<int>> t(h, vector<int>(w, 0));
  rep(i, h) rep(j, w) cin >> c[i][j];

  // 綺麗なタイルが何個連続しているかをDP
  rep(j, w) {
    rep(i, h) {
      if (c[i][j]) {
        t[i][j] = 0;
      } else {
        t[i][j] = (i > 0) ? t[i - 1][j] + 1 : 1;
      }
    }
  }

  int maxv = 0;
  rep(i, h) maxv = max(maxv, getLargestRectangle(w, t[i]));
  cout << maxv << endl;
}