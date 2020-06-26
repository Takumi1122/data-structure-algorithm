#include <iostream>
using namespace std;

int n;
int a[11000];  // 最大 10000 個なので余裕を持って 11000 に

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  bool res = false;  // 初期値は false に
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) res = true;  // 0 だったら true に (フラグを立てる)
  }

  if (res)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}