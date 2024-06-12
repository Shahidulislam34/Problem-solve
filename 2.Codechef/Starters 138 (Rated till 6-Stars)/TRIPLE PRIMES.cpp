///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
vector<int>prim;
const int N = 100000;
bool vis[N + 5];
void pre_cal(){
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i * i <= N; ++i){
        if (vis[i] == 0){
            for (int j = i * i; j <= N; j += i){
                vis[j] = 1;
            }
        }
    }
    vis[0] = vis[1] = 1;
    for (int i = 3; i <= N; ++i){
        if (vis[i] == 0) prim.push_back(i);
    }
}

bool check(int n){
    if (n % 2 == 0 && (n != 2)) return false;
    if (n < 2) return false;

    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0) return false;
    }
    return true;
}

void sol(){
    int n;
    cin >> n;
    n -= 4;
    for (auto x : prim){
        int dif = n - (x * x);
        if (dif < 0) break;
        int sq = sqrt(dif);
        if (sq * sq == dif && sq != x  && sq != 2&& (dif + x * x == n) && vis[sq] == 0){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    pre_cal();
    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}






