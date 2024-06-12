#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

int ex[32 + 5];

void sol(){
    int n, m;
    cin >> n >> m;
    int a = max(0ll, n - m), b = n + m;
    int val = a;
    bitset<31>bs(a);
    int res = 0;
    for (int i = 0; i <= 30; ++i){
        if (bs[i] == 1){
            res += ex[i];
            val -= ex[i];
            continue;
        }
        else if (bs[i] == 0 && val + ex[i] >= a && val + ex[i] <= b){
            res += ex[i];
        }
    }
    cout << res << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int m = 1;
    for (int i = 0; i <= 31; ++i){
        ex[i] = m;
        m *= 2;
    }
    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}



