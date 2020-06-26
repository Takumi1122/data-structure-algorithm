#include <iostream>
#include <vector>  // vector をインクルードします！
using namespace std;

int n;
int a[11000];  // 最大 10000 個なので余裕を持って 11000 に

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<int> findIDs;  // 0 の場所を格納
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {  // 見つかったら、
      findIDs.push_back(
          i);  // 場所を記録して、今度は break しない！！！ (すべて求めたいため)
    }
  }

  // 結果出力
  cout << "nums of zeros: " << findIDs.size() << endl;  // 何個あったか
  for (int i = 0; i < (int)findIDs.size(); i++) {
    cout << findIDs[i] << " th" << endl;
  }
}