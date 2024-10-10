#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
vector<int>point[1001];
vector<vector<int>>dp;
int n, k;

int DP(int state, int carry) {
    if (carry >= k) return 0;
    else if (state > n) return INT_MAX;
    if (dp[state][carry] != -1) return dp[state][carry];

    int sum = DP(state + 1, carry);
    for (int i = 0; i < min(k - carry, (int)point[state].size()); ++i) {
        int val = DP(state + 1, carry + i + 1);
        if (val != INT_MAX) sum = min(sum, val + point[state][i]);
    }
    return dp[state][carry] = sum;
}

void sol(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        point[i].clear();
        int ww, hh;
        cin >> ww >> hh;
        if (ww > hh) swap(ww, hh);
        int sum = 0;
        while(hh > ww) {
            sum += ww;
            point[i].push_back(sum);
            --hh;
        }
        while(ww > 0) {
            sum += ww; point[i].push_back(sum);
            sum += ww - 1; point[i].push_back(sum);
            --ww;
        }
    }
    dp.assign(n + 1, vector<int>(k + 1, -1));
    int res = DP(1, 0);
    cout << (res == INT_MAX ? -1 : res) << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}

