#include <iostream>

//リストの要素を定義する構造体
struct cell {
  cell* next;  //次の要素を表すポインタ
  int key;     //キー(数値)
  int value;   //値(数値)
};

//リストに要素を挿入する関数
void insertCell(cell* head, int key, int value) {
  //ここを埋める(課題1)
  while (head->next) {
    head = head->next;
  }
  head->next = new cell{nullptr, key, value};
}

//リストからkeyに対応する要素を削除する関数
void deleteCell(cell* head, int key) {
  //ここを埋める(課題1)
  if (!head->next) return;
  while (head->next->key != key && head->next) {
    head = head->next;
  }
  if (!head->next) return;
  head->next = head->next->next;
}

//リストからkeyに対応する要素の値を得る関数
int searchCell(const cell* head, int key) {
  //ここを埋める(課題1)
  if (!head->next) return -1;
  while (head->next->key != key) {
    head = head->next;
  }
  return head->next->value;
}

//リストを全て表示する関数
void printCell(const cell* head) {
  std::cout << "[ ";
  const cell* it = head;
  while (it->next) {
    std::cout << it->next->value << ", ";
    it = it->next;
  }
  std::cout << "]" << std::endl;
}

const int kTableSize = 10;
cell table[kTableSize];

//ハッシュ関数
//ここでは簡単のため単純な剰余を用いるが, 実際にはもっと複雑なものが考えられる
int hash_function(int key) { return key % kTableSize; }

//テーブルに要素を挿入する関数
void insertTable(int key, int value) {
  //ここを埋める
  insertCell(&table[hash_function(key)], key, value);
}

//デーブルからkeyに対応する要素を削除する関数
void deleteTable(int key) {
  //ここを埋める
  deleteCell(&table[hash_function(key)], key);
}

//テーブルからkeyに対応する要素の値を得る関数
int searchTable(int key) {
  //ここを埋める
  return searchCell(&table[hash_function(key)], key);
}

//テーブルの中身を全て表示する関数
void printTable() {
  for (const auto& it : table) {
    printCell(&it);
  }
  std::cout << std::endl;
}

int main() {
  insertTable(1, 1);
  insertTable(2, 2);
  insertTable(3, 3);
  insertTable(12, 12);
  insertTable(13, 13);
  insertTable(22, 22);
  printTable();

  deleteTable(12);
  deleteTable(3);
  printTable();

  std::cout << searchTable(22) << std::endl;
  std::cout << searchTable(4) << std::endl;
  return 0;
}
