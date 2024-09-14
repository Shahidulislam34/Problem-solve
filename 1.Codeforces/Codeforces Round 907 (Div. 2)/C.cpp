///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    sort(v.begin() + 1, v.begin() + n + 1);
    int last = n, res = 0, sum = 0, tmp;
    for (int i = 1; i <= last; ++i){
        tmp = sum + v[i];
        if (tmp >= v[last]){
            if (i == last){
                tmp = sum + v[i];
                res += tmp / 2 + 1;
                if (tmp > 1 && tmp % 2 == 1) ++res;
                sum = 0;
            }
            else {
                res += v[last] + 1;
                sum = tmp - v[last];
                --last;
            }
        }
        else sum += v[i];
    }
    if (sum > 0) res += sum / 2 + 1;
    if (sum > 1 && sum % 2 == 1) ++res;
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}
