#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 行列累乗 O(n^3 * log(k))
// 蟻本P184: Matrix Power Series

int M;

// matrix
template <class T>
struct Matrix {
  vector<vector<T> > val;
  Matrix(int n = 1, int m = 1, T v = 0) : val(n, vector<T>(m, v)) {}
  void init(int n, int m, T v = 0) { val.assign(n, vector<T>(m, v)); }
  void resize(int n, int m) {
    val.resize(n);
    for (int i = 0; i < n; ++i) val[i].resize(m);
  }

  Matrix<T> &operator=(const Matrix<T> &A) {
    val = A.val;
    return *this;
  }

  size_t size() const { return val.size(); }
  vector<T> &operator[](int i) { return val[i]; }
  const vector<T> &operator[](int i) const { return val[i]; }
  friend ostream &operator<<(ostream &s, const Matrix<T> &M) {
    s << endl;
    for (int i = 0; i < (int)M.size(); ++i) s << M[i] << endl;
    return s;
  }
};

template <class T>
Matrix<T> operator*(const Matrix<T> &A, const Matrix<T> &B) {
  Matrix<T> R(A.size(), B[0].size());
  for (int i = 0; i < A.size(); ++i)
    for (int j = 0; j < B[0].size(); ++j)
      for (int k = 0; k < B.size(); ++k) R[i][j] += A[i][k] * B[k][j] % M;
  return R;
}

// O(m^3 * log(n))
template <class T>
Matrix<T> pow(const Matrix<T> &A, long long n) {
  Matrix<T> R(A.size(), A.size());
  auto B = A;
  for (int i = 0; i < A.size(); ++i) R[i][i] = 1;
  while (n > 0) {
    if (n & 1) R = R * B;
    B = B * B;
    n >>= 1;
  }
  return R;
}

template <class T>
vector<T> operator*(const Matrix<T> &A, const vector<T> &B) {
  vector<T> v(A.size());
  for (int i = 0; i < A.size(); ++i)
    for (int k = 0; k < B.size(); ++k) v[i] += A[i][k] * B[k];
  return v;
}

template <class T>
Matrix<T> operator+(const Matrix<T> &A, const Matrix<T> &B) {
  Matrix<T> R(A.size(), A[0].size());
  for (int i = 0; i < A.size(); ++i)
    for (int j = 0; j < A[0].size(); ++j) R[i][j] = A[i][j] + B[i][j];
  return R;
}

template <class T>
Matrix<T> operator-(const Matrix<T> &A, const Matrix<T> &B) {
  Matrix<T> R(A.size(), A[0].size());
  for (int i = 0; i < A.size(); ++i)
    for (int j = 0; j < A[0].size(); ++j) R[i][j] = A[i][j] - B[i][j];
  return R;
}

int main() {
  ll n, k;
  cin >> n >> k >> M;
  Matrix<ll> A(n, n, 0);
  rep(i, n) rep(j, n) cin >> A[i][j];

  Matrix<ll> B(n * 2, n * 2, 0);
  rep(i, n) {
    rep(j, n) { B[i][j] = A[i][j]; }
    B[n + i][i] = B[n + i][n + i] = 1;
  }
  B = pow(B, k + 1);

  rep(i, n) {
    rep(j, n) {
      int a = B[n + i][j] % M;
      if (i == j) a = (a + M - 1) % M;
      printf("%d%c", a, j + 1 == n ? '\n' : ' ');
    }
  }
}