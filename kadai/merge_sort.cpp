#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

// マージソート o(n * log(n)) 安定ソート○　内部ソート×

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
  // 入力
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  // マージソート
  mergeSort(a, 0, n);

  // 出力
  rep(i, n) cout << a[i] << ", ";
  cout << endl;

  return 0;
}