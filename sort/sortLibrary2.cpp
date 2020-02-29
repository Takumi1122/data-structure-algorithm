#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;  // 要素数
  vector<int> a;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a_temp;
    cin >> a_temp;
    a.push_back(a_temp);
  }

  sort(a.begin(), a.end());  // a を小さい順にソート

  // 出力
  for (int i = 0; i < N; i++) cout << a[i] << " ";
  cout << endl;
}