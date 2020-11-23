#include <iostream>

//ノードを表す構造体
struct node {
  int key;
  node *left = nullptr, *right = nullptr, *parent = nullptr;
};

//根ノード
node* root;

// nodeのキーを得る関数
int& key(node* x) { return x->key; }

// nodeの左の子を得る関数
node*& left(node* x) { return x->left; }

// nodeの右の子を得る関数
node*& right(node* x) { return x->right; }

// nodeの親を得る関数
node*& parent(node* x) { return x->parent; }

//左端のノード(最小)を得る関数
node* minimum(node* x = root) {
  if (!left(x)) {
    return x;
  }
  return minimum(left(x));
}

// nodeの次の節点を得る関数
node* successor(node* x) {
  node* y;
  if (right(x)) {
    return minimum(right(x));
  }
  y = parent(x);
  while (y && x == right(y)) {
    x = y;
    y = parent(y);
  }
  return y;
}

// node以下にあるkeyに対応するノードを返す関数
//見つからなければnullを返す
node* searchNode(int search_key, node* x = root) {
  //ここを埋める
  if (x == nullptr || search_key == key(x)) return x;
  if (search_key < key(x))
    return searchNode(search_key, left(x));
  else
    return searchNode(search_key, right(x));
}

//新しいノードzを挿入する関数
void insertNode(node* z) {
  //ここを埋める
  node *x, *y;
  y = nullptr;
  x = root;
  // z を挿入する場所 x を決める
  while (x != nullptr) {
    y = x;
    if (key(z) < key(x))
      x = left(x);
    else
      x = right(x);
  }

  parent(z) = y;  // z の親を y にする
  if (y == nullptr)
    root = z;  // T が空なら z が根節点
  else if (key(z) < key(y))
    left(y) = z;  // y の子を z にする
  else
    right(y) = z;
}

//既に木に存在しているノードzを削除する関数
// zはnullである可能性があるのでそれを弾く
void deleteNode(node* z) {
  //ここを埋める
  if (z == nullptr) return;
  node *x, *y;
  if (left(z) == nullptr || right(z) == nullptr)
    y = z;  // z の子の数が1以下
  else
    y = successor(z);  // z は2つの子を持つ

  if (left(y) != nullptr)
    x = left(y);
  else
    x = right(y);  // x は y の子

  if (x != nullptr) parent(x) = parent(y);  // y を削除する
  if (parent(y) == nullptr)
    root = x;  // y が根なら x を根に
  else if (y == left(parent(y)))
    left(parent(y)) = x;  // y の親と子をつなぐ
  else
    right(parent(y)) = x;
  if (y != z) {
    key(z) = key(y);  // y の内容を z に移動
  }
}

//木をクリアする関数(メモリ解放用)
void clearNode(node* x = root) {
  if (!x) {
    return;
  }
  clearNode(left(x));
  clearNode(right(x));
  delete x;
}

// printTree用の補助関数
void inorder(node* x) {
  if (x) {
    inorder(left(x));
    std::cout << key(x) << ", ";
    inorder(right(x));
  }
}

//木全体を表示する関数
void printTree() {
  std::cout << "[";
  inorder(root);
  std::cout << "]" << std::endl;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int input;
    std::cin >> input;
    node* newNode = new node;
    newNode->key = input;
    insertNode(newNode);
  }
  printTree();

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int input;
    std::cin >> input;
    deleteNode(searchNode(input));
  }
  printTree();
  clearNode();
}
