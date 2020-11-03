#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 凸包 Convex Hull
// O(nlog(n))

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_A
*/

////////////////////////////
// 基本要素 (点, 線分, 円)
////////////////////////////

using DD = double;
const DD INF = 1LL << 60;  // to be set appropriately
const DD EPS = 1e-10;      // to be set appropriately
const DD PI = acosl(-1.0);
DD torad(int deg) { return (DD)(deg)*PI / 180; }
DD todeg(DD ang) { return ang * 180 / PI; }

/* Point */
struct Point {
  DD x, y;
  Point(DD x = 0.0, DD y = 0.0) : x(x), y(y) {}
  friend ostream &operator<<(ostream &s, const Point &p) {
    return s << '(' << p.x << ", " << p.y << ')';
  }
};
inline Point operator+(const Point &p, const Point &q) {
  return Point(p.x + q.x, p.y + q.y);
}
inline Point operator-(const Point &p, const Point &q) {
  return Point(p.x - q.x, p.y - q.y);
}
inline Point operator*(const Point &p, DD a) { return Point(p.x * a, p.y * a); }
inline Point operator*(DD a, const Point &p) { return Point(a * p.x, a * p.y); }
inline Point operator*(const Point &p, const Point &q) {
  return Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x);
}
inline Point operator/(const Point &p, DD a) { return Point(p.x / a, p.y / a); }
inline Point conj(const Point &p) { return Point(p.x, -p.y); }
inline Point rot(const Point &p, DD ang) {
  return Point(cos(ang) * p.x - sin(ang) * p.y,
               sin(ang) * p.x + cos(ang) * p.y);
}
inline Point rot90(const Point &p) { return Point(-p.y, p.x); }
inline DD cross(const Point &p, const Point &q) {
  return p.x * q.y - p.y * q.x;
}
inline DD dot(const Point &p, const Point &q) { return p.x * q.x + p.y * q.y; }
inline DD norm(const Point &p) { return dot(p, p); }
inline DD abs(const Point &p) { return sqrt(dot(p, p)); }
inline DD amp(const Point &p) {
  DD res = atan2(p.y, p.x);
  if (res < 0) res += PI * 2;
  return res;
}
inline bool eq(const Point &p, const Point &q) { return abs(p - q) < EPS; }
inline bool operator<(const Point &p, const Point &q) {
  return (abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y);
}
inline bool operator>(const Point &p, const Point &q) {
  return (abs(p.x - q.x) > EPS ? p.x > q.x : p.y > q.y);
}
inline Point operator/(const Point &p, const Point &q) {
  return p * conj(q) / norm(q);
}

/* Line */
struct Line : vector<Point> {
  Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)) {
    this->push_back(a);
    this->push_back(b);
  }
  friend ostream &operator<<(ostream &s, const Line &l) {
    return s << '{' << l[0] << ", " << l[1] << '}';
  }
};

/* Circle */
struct Circle : Point {
  DD r;
  Circle(Point p = Point(0.0, 0.0), DD r = 0.0) : Point(p), r(r) {}
  friend ostream &operator<<(ostream &s, const Circle &c) {
    return s << '(' << c.x << ", " << c.y << ", " << c.r << ')';
  }
};

int ccw(const Point &a, const Point &b, const Point &c) {
  if (cross(b - a, c - a) > EPS) return 1;
  if (cross(b - a, c - a) < -EPS) return -1;
  if (dot(b - a, c - a) < -EPS) return 2;
  if (norm(b - a) < norm(c - a) - EPS) return -2;
  return 0;
}

///////////////////////
// 多角形アルゴリズム
///////////////////////

// アンドリューのアルゴリズム O(nlog(n))
vector<Point> andrewScan(vector<Point> ps) {
  vector<Point> u, l;
  if (ps.size() < 3) ps;
  sort(ps.begin(), ps.end());
  // xが小さいものから2つ u に追加
  u.push_back(ps[0]);
  u.push_back(ps[1]);
  // xが大きいものから2つ l に追加
  l.push_back(ps[ps.size() - 1]);
  l.push_back(ps[ps.size() - 2]);

  // 凸包上部を生成
  for (int i = 2; i < ps.size(); i++) {
    for (int n = u.size(); n >= 2 && ccw(u[n - 2], u[n - 1], ps[i]) == 1; n--) {
      u.pop_back();
    }
    u.push_back(ps[i]);
  }

  // 凸包下部を生成
  for (int i = ps.size() - 3; i >= 0; i--) {
    for (int n = l.size(); n >= 2 && ccw(l[n - 2], l[n - 1], ps[i]) == 1; n--) {
      l.pop_back();
    }
    l.push_back(ps[i]);
  }

  // 時計周りになるように凸包の点の列を生成
  reverse(l.begin(), l.end());
  for (int i = u.size() - 2; i >= 1; i--) l.push_back(u[i]);

  return l;
}

int main() {
  int n;
  cin >> n;
  vector<Point> ps(n);
  rep(i, n) cin >> ps[i].x >> ps[i].y;
  auto ans = andrewScan(ps);
  pair<double, double> minv = {11000, 11000};
  int minp = -1;
  for (int i = 0; i < (int)ans.size(); ++i) {
    if (minv > make_pair(ans[i].y, ans[i].x)) {
      minv = make_pair(ans[i].y, ans[i].x);
      minp = i;
    }
  }
  cout << ans.size() << endl;
  rep(i, ans.size()) {
    int j = (i + minp) % ans.size();
    cout << ans[j].x << " " << ans[j].y << endl;
  }
  return 0;
}