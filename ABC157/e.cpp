#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;
int N, Q;
string S;
vector<set<int> > pls;

void solve() {
  pls.assign(26, set<int>({INF}));
  for (int i = 0; i < N; ++i) pls[S[i] - 'a'].insert(i);

  while (Q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int ind;
      char nc;
      cin >> ind >> nc;
      --ind;
      auto pc = S[ind];
      S[ind] = nc;
      pls[pc - 'a'].erase(ind);
      pls[nc - 'a'].insert(ind);
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      int res = 0;
      for (int c = 0; c < 26; ++c) {
        if (pls[c].empty()) continue;
        int lid = *pls[c].lower_bound(l);
        int rid = *pls[c].lower_bound(r);
        if (rid > lid) ++res;
      }
      cout << res << endl;
    }
  }
}

int main() {
  cin >> N >> S >> Q;
  solve();
}