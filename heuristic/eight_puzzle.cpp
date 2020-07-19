#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define N 3
#define N2 9

struct Puzzle {
  int f[N2];
  int space;
  string path;

  bool operator<(const Puzzle &p) const {
    rep(i, N2) {
      if (f[i] == p.f[i]) continue;
      return f[i] > p.f[i];
    }
    return false;
  }
};

static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, -1, 0, 1};
static const char dir[4] = {'u', 'l', 'd', 'r'};

bool isTarget(Puzzle p) {
  rep(i, N2) {
    if (p.f[i] != (i + 1)) return false;
  }
  return true;
}

string bfs(Puzzle s) {
  queue<Puzzle> Q;
  map<Puzzle, bool> V;
  Puzzle u, v;
  s.path = "";
  Q.push(s);
  V[s] = true;

  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    if (isTarget(u)) return u.path;
    int sx = u.space / N;
    int sy = u.space % N;
    rep(r, 4) {
      int tx = sx + dx[r];
      int ty = sy + dy[r];
      if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
      v = u;
      swap(v.f[u.space], v.f[tx * N + ty]);
      v.space = tx * N + ty;
      if (!V[v]) {
        V[v] = true;
        v.path += dir[r];
        Q.push(v);
      }
    }
  }

  return "unsolvable";
}

int main() {
  Puzzle in;

  rep(i, N2) {
    cin >> in.f[i];
    if (in.f[i] == 0) {
      in.f[i] = N2;
      in.space = i;
    }
  }
  string ans = bfs(in);
  cout << ans.size() << endl;

  return 0;
}