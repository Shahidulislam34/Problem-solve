///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, l , r;
    cin >> n >> l >> r;
    vector<int>v(n + 5, 0);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    queue<int>Q;
    int sum = 0, res = 0;
    for (int i = 1; i <= n; ++i){
        Q.push(v[i]);
        sum += v[i];
        if (sum > r){
            while(!Q.empty()){
                sum -= Q.front();
                Q.pop();
                if (sum >= l && sum <= r) {
                    ++res;
                    while(!Q.empty()) Q.pop();
                    sum = 0;
                    break;
                }
                else if (sum < l)
                    break;
            }
        }
        else if (sum >= l && sum <= r) {
            ++res;
            while(!Q.empty()) Q.pop();
            sum = 0;
        }
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}










