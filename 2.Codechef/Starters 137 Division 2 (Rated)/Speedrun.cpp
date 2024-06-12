#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n, ran;
    cin >> n >> ran;
    vector<int>pos(n + 5), heal(n + 5);
    for (int i = 1; i <= n; ++i)cin >> pos[i];
    for (int i = 1; i <= n; ++i)cin >> heal[i];

    int flag = 0, cnt = 0, ind = 0, ok = 0;
    for (int i = 1; i <= n; ++i){
        cnt += heal[i];
        if (cnt <= pos[i])continue;
        else {
            ind = pos[i] + 2 * ran;
            cnt -= heal[i];
            for (; i <= n; ++i){
                if (pos[i] > ind){
                    break;
                }
            }
            for (; i <= n; ++i){
                cnt += heal[i];
                if (cnt > pos[i]){
                    cout << "NO" << endl;
                    return;
                }
            }
            break;
        }
    }
    cout << "YES" << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}




