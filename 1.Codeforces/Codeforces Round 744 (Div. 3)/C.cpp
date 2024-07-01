#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    deque<int>dq;
    for (int i = 1; i <= n; ++i) cin>> v[i];
    dq.push_back(v[1]);
    for (int i = 2; i <= n; ++i){
        if (dq.front() > v[i])dq.push_front(v[i]);
        else dq.push_back(v[i]);
    }
    for (auto x : dq) cout << x << ' '; cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}










