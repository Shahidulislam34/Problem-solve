#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int>v(n + 5);
  for (int i = 1; i <= n; ++i) cin >> v[i];
  for (int i = n - k + 1; i <= n; ++i) cout << v[i] << ' ';
  for (int i = 1; i <= n - k; ++i) cout << v[i] << ' '; cout << endl;
  return 0;
}
