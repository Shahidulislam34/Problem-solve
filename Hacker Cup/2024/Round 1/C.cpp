#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

void sol(int tt){
    int n;
    cin >> n;
    int arr[n + 1][2 + 1];
    for (int i = 1; i <= n; ++i) cin >> arr[i][1] >> arr[i][2];
    int s = 0, t = 1;
    for (int i = 1; i <= n; ++i) {
        int si, ti;
        si = i;
        ti = arr[i][1];
        if (si * t >= s * ti) s = si, t = ti;
    }
    cout << s << ' ' << t << endl;

}

int32_t main(){
//    faster();
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; ++i) sol(i);
    return 0;
}






