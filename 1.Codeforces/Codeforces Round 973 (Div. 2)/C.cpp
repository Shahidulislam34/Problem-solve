#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

void sol(){
    int n;
    cin >> n;

    string res;
    if (n == 1) {
        cout << '?' << ' ' << "1" << endl;
        int x; cin >> x;
        if (x == 1) {
            cout << "! " << "1" << endl; return;
        }
        else {
            cout << "! " << "0" << endl; return;
        }
    }

    int flag = 0, sz = 0;
    while (n >= 2) {
        res.clear();
        res = "01";
        cout << '?' << ' ' << res << endl;
        int x; cin >> x;
        if (x == 1) {
            sz = 2; flag = 1;
            break;
        }
        res.clear();
        res = "10";
        cout << '?' << ' ' << res << endl;
        cin >> x;
        if (x == 1) {
            sz = 2; flag = 1;
            break;
        }
        if (flag == 0) {
            res.clear();
            break;
        }
    }
    if (flag == 0) {
        cout << '?' << ' ' << '1' << endl;
        int m; cin >> m;
        if (m == 1) {
            res.clear();
            for (int i = 1; i <= n; ++i) res.push_back('1');
            cout << "! " << res << endl; return;
        }
        else {
            res.clear();
            for (int i = 1; i <= n; ++i) res.push_back('0');
            cout << "! " << res << endl; return;
        }
    }
    else {
        while(sz < n) {
            int f2 = 0;
            res.push_back('0'); ++sz;
            cout << '?' << ' ' << res << endl;
            int x; cin >> x;
            if (x == 0) {
                res.pop_back();
                --sz;
                ++f2;
            }
            if (sz == n) break;
            res.push_back('1'); ++sz;
            cout << '?' << ' ' << res << endl;
            cin >> x;
            if(x == 0) {
                res.pop_back();
                --sz;
                ++f2;
            }
            if (sz == n || f2 == 2) break;
        }

        while(sz < n) {
            int f2 = 0;
            res.insert(res.begin(), '1'); ++sz;
            cout << '?' << ' ' << res << endl;
            int x; cin >> x;
            if (x == 0) {
                res.erase(res.begin());
                --sz;
                ++f2;
            }
            if (sz == n) break;

            res.insert(res.begin(), '0'); ++sz;
            cout << '?' << ' ' << res << endl;
            cin >> x;
            if (x == 0) {
                res.erase(res.begin());
                --sz;
                ++f2;
            }
            if (sz == n || f2 == 2) break;
        }
        cout << '!' << ' ' << res << endl;
    }


}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}




