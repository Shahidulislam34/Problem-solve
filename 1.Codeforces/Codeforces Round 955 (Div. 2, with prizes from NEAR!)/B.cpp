///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int v, c, o;
    cin >> v >> c >> o;
    int tmp = o;
    while(v != 1 && o > 0){
        int m = (v / c + 1) * c;
        if (m - v <= o) o -= m - v, v += m - v;
        else v += o, o = 0;
        while(v % c == 0) v /= c;
    }
    if (o == 0) {
        cout << v << endl;
        return;
    }
    tmp = o;
    tmp %= (c - 1);
    v += tmp;
    cout << v << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}










