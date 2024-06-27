///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n;
const int N = 2e5 + 5;
vector<int>v(N + 5);

int calculation(int a, int b, int c){
    vector<pair<pair<int, int>, int>>pv;
    for (int i = 1; i <= n - 2; ++i)
        pv.push_back({{v[i + a - 1], v[i + b - 1]}, v[i + c - 1]});
    sort(pv.begin(), pv.end());
    int cnt = 0, sum = 0, res = 0, val;
    for (int i = 0; i < n - 2; ++i){
        cnt = 0;
        val = pv[i].second;
        pair<int, int>pp = pv[i].first;
        for (; i < n - 2; ++i){
            if (pv[i].first == pp && pv[i].second == val){
                ++cnt;
                continue;
            }
            else break;
        }
        res += sum * cnt;
        sum += cnt;
        if (pv[i].first != pp) sum = 0;
        --i;
    }
    return res;
}


void sol(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    int res = 0;
    res += calculation(1, 2, 3);
    res += calculation(1, 3, 2);
    res += calculation(2, 3, 1);
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}
