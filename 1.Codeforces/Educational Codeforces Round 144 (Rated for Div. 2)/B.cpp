#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void sol(){
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = '0' + a;
    b = '0' + b;

    if (a[1] == b[1]) {
        cout << "YES" << endl;
        cout << a[1] << '*' << endl;
        return;
    }
    else if (a[n] == b[m]) {
        cout << "YES" << endl;
        cout << '*' << a[n] << endl;
        return;
    }
    else if (n == 1 || m == 1) {
        cout << "NO" << endl;
        return;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i] == b[j] && a[i + 1] == b[j + 1]) {
                cout << "YES" << endl;
                cout << '*' << a[i] << a[i + 1] << '*' << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}






