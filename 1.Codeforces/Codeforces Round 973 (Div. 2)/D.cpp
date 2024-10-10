#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

int n;
vector<int>v;

int cal_maximum() {
    int l = 1, r = *max_element(v.begin() + 1, v.begin() + n + 1), mid, res = r;
    while(l <= r){
        mid = (l + r) / 2;
        int sum = 0, flag = 1;
        for (int i = n; i >= 1; --i) {
            sum += v[i];
            if (mid * (n - i + 1) < sum) {
                flag = 0;
                break;
            }
        }
        flag ? (res = mid, r = mid - 1) : l = mid + 1;
    }
    return res;
}

int cal_minimum() {
    int l = 1, r = *max_element(v.begin() + 1, v.begin() + n + 1), mid, res = 1;
    while(l <= r) {
        mid = (l + r) / 2;
        int sum = 0, flag = 1;
        for (int i = 1; i <= n; ++i) {
            sum += v[i];
            if (i * mid > sum) {
                flag = 0;
                break;
            }
        }
        flag ? res = mid, l = mid + 1 : r = mid - 1;
    }
    return res;
}

void sol(){
    cin >> n;
    v.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    int mx = cal_maximum();
    int mn = cal_minimum();
    cout << mx - mn << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}




