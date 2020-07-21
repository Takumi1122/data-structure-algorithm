#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// マージソート o(n * log(n)) 安定ソート○　内部ソート×

/* 配列 a の [left, right) をソートします */
void mergeSort(vector<int> &a, int left, int right) {
  if (right - left == 1) return;
  int mid = left + (right - left) / 2;

  // 左半分 [left, mid) をソート
  mergeSort(a, left, mid);

  // 右半分 [mid, right) をソート
  mergeSort(a, mid, right);

  // 一旦「左」と「右」のソート結果をコピーしておく (右側は左右反転)
  vector<int> buf;
  for (int i = left; i < mid; i++) buf.push_back(a[i]);
  for (int i = right - 1; i >= mid; i--) buf.push_back(a[i]);

  // マージする
  int iterator_left = 0;                     // 左側のイテレータ
  int iterator_right = (int)buf.size() - 1;  // 右側のイテレータ
  for (int i = left; i < right; i++) {
    // 左側採用
    if (buf[iterator_left] <= buf[iterator_right]) {
      a[i] = buf[iterator_left++];
    }
    // 右側採用
    else {
      a[i] = buf[iterator_right--];
    }
  }
}

int main() {
  int n;  // 要素数
  cin >> n;
  vector<int> a(n);  // 整列したい配列ベクトル (サイズ を n に初期化)
  rep(i, n) {
    cin >> a[i];  // 整列したい配列を取得
  }

  /* マージソート */
  mergeSort(a, 0, n);

  rep(i, n) cout << a[i] << " ";
  cout << endl;

  return 0;
}