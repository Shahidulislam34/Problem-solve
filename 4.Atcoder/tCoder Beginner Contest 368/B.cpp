#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int>v(n + 5, 0);
  for (int i = 1; i <= n; ++i) cin >> v[i];

  int res = 0;
  while(1) {
    int fst = INT_MIN, scd = INT_MIN, ind1 = 0, ind2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (fst < v[i]) {
            scd = fst;
            fst = v[i];
            ind2 = ind1;
            ind1 = i;
        }
        else if (scd < v[i]) {
            scd = v[i];
            ind2 = i;
        }
    }
    if (fst >= 1 && scd >= 1) {
        --v[ind1];
        --v[ind2];
        ++res;
    }
    else break;
  }
  cout << max(0, res) << endl;
  return 0;
}

