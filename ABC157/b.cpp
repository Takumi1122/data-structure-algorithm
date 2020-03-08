#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
int A[3][3];
int B[15];
vector<int> C;

bool contain(int a, int b, int c, vector<int> &C) {
  auto itr1 = find(C.begin(), C.end(), a);
  size_t index1 = distance(C.begin(), itr1);
  auto itr2 = find(C.begin(), C.end(), b);
  size_t index2 = distance(C.begin(), itr2);
  auto itr3 = find(C.begin(), C.end(), c);
  size_t index3 = distance(C.begin(), itr3);
  if (index1 != C.size() && index2 != C.size() &&
      index3 != C.size()) {  // 発見できたとき
    return true;
  } else {  // 発見できなかったとき
    return false;
  }
}

int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) cin >> A[i][j];
  }

  cin >> N;
  for (int i = 0; i < N; i++) cin >> B[i];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < N; k++) {
        if (A[i][j] == B[k]) {
          C.push_back((i + 1) * 10 + (j + 1));
        }
      }
    }
  }

  bool judge = (contain(11, 12, 13, C) || contain(21, 22, 23, C) ||
                contain(31, 32, 33, C) || contain(11, 22, 33, C) ||
                contain(13, 22, 31, C) || contain(11, 21, 31, C) ||
                contain(12, 22, 32, C) || contain(13, 23, 33, C));

  if (judge) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}