#include <bits/stdc++.h>
using namespace std;
#define int long long
string a, b;
int n, k, l, r;

bool possible() {
    int mx = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        char ch = b[i];
        l = i;
        for (; i <= n; ++i) {
            if (b[i] != ch) {
                --i;
                break;
            }
            ++cnt;
        }
        mx = max(mx, cnt);
        if (mx >= k) {
            r = min(n, i);
            break;
        }
    }
    if (mx >= k) return true;
    else return false;
}

void sol() {
    cin >> n >> k;
    cin >> a >> b;
    a = '0' + a;
    b = '0' + b;
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    if (!possible()) {
        cout << -1 << endl;
        return;
    }
    vector<pair<int, char>>res;
    for (int i = 1; i <= r - k + 1; ++i) {
        res.push_back({i, b[i]});
    }
    for (int i = n; i >= r; --i) {
        res.push_back({i - k + 1, b[i]});
    }
    cout << res.size() << endl;
    for (auto [x, y] : res) cout << x << ' ' << y << endl;
}

int32_t main() {
	int tt = 1;
	cin >> tt;
	while(tt--) sol();
    return 0;
}
