///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 200;
vector<int>graph(N + 5), v(N + 5), per;
int n;
string str, tmp;
bool vis[N + 5];

int find_operation(string &tmp, vector<int> &per){
    string now = tmp;
    int sz = tmp.size(), ope = 0;
    while(1){
        ++ope;
        for (int i = 0; i < sz; ++i){
            now[i] = str[per[i]];
        }
        if (tmp == now) break;
        str[per[sz - 1]] = now[0];
        for (int i = 1; i < sz; ++i) str[per[i - 1]] = now[i];
    }
    return ope;
}

void find_cycle(int ind){
    if (vis[ind] == 1) return;
    vis[ind] = 1;
    tmp.push_back(str[ind]);
    per.push_back(graph[ind]);
    find_cycle(graph[ind]);
}

void sol(){
    str.clear();
    graph.clear();
    cin >> n;
    cin >> str; str = '0' + str;
    for (int i = 1; i <= n; ++i) cin >> v[i];

    for (int i = 1; i <= n; ++i) graph[i] = v[i];
    memset(vis, false, sizeof(vis));
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == false){
            tmp.clear();
            per.clear();
            find_cycle(i);
            int m = find_operation(tmp, per);
            res = (res * m) / __gcd(res, m);
        }
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}



