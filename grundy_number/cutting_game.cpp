#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 蟻本P283: Cutting Game

const int MAX_WH = 200;
int mem[MAX_WH + 1][MAX_WH + 1];

int grundy(int w, int h) {
  if (mem[w][h] != -1) return mem[w][h];

  set<int> s;
  for (int i = 2; i <= w - 2; i++) s.insert(grundy(i, h) ^ grundy(w - i, h));
  for (int i = 2; i <= h - 2; i++) s.insert(grundy(w, i) ^ grundy(w, h - i));

  int res = 0;
  while (s.count(res)) res++;
  return mem[w][h] = res;
}

int main() {
  int w, h;
  cin >> w >> h;

  rep(i, MAX_WH + 1) rep(j, MAX_WH + 1) mem[i][j] = -1;

  if (grundy(w, h) != 0)
    cout << "WIN" << endl;
  else
    cout << "LOSE" << endl;
  return 0;
}