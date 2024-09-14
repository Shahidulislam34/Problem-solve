#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int32_t main() {
  int n;
  cin >> n;
  vector<int>v(n + 5);
  for (int i = 1; i <= n; ++i) cin >> v[i];

  int k = 0;
  for (int i = 1; i <= n; ++i) {
        int need = min(2ll, 2 - (k % 3));
        k += min(need, v[i]);
        v[i] -= min(need, v[i]);
        k += (v[i] / 5) * 3;
        v[i] -= (v[i] / 5) * 5;
        if (v[i] > 0 && v[i] <= 3) ++k;
        else if (v[i] > 0 && v[i] == 4) k += 2;
  }
  cout << k << endl;
  return 0;
}


