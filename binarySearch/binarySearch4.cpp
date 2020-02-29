#include <iostream>
using namespace std;

int main() {
  cout << "Start Game!" << endl;

  /* A さんの年齢の候補を表す区間を、[left, right) と表します */
  /* A さんは、left 歳以上 right 歳未満、right
   * 歳自体は候補に含まれないことに注意 */
  int left = 20, right = 36;

  /* A さんの年齢を 1 つに絞れないうちは繰り返す */
  while (right - left > 1) {
    int mid = left + (right - left) / 2;  // 区間の真ん中

    /* mid 歳以上かを聞いて、回答を yes/no で受け取る */
    cout << "Is the age same or more than " << mid << " ? (yes / no)" << endl;
    string ans;
    cin >> ans;

    /* 回答の応じて、年齢を絞る */
    if (ans == "yes")
      left = mid;  // mid 歳以上なら、mid 歳以上 right 歳以下になるように
    else
      right = mid;  // mid 歳未満なら、left 歳以上 mid 歳未満になるように
  }

  /* ズバリ当てる！ */
  cout << "The age is " << left << "!" << endl;
}