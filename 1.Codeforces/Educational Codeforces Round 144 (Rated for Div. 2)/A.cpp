#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void sol(){
    string FB;
    for (int i = 1; i <= 100; ++i) {
        if (i % 3 == 0) FB.push_back('F');
        if (i % 5 == 0) FB.push_back('B');
    }

    int n;
    cin >> n;
    string str;
    cin >> str;
    for (int i = 0; i <= 8; ++i) {
        int ind = i, flag = 1;
        for (int i = 0; i < n; ++i) {
            if (FB[ind] != str[i]) {
                flag = 0;
                break;
            }
            ++ind;
        }
        if (flag) {
            cout << "YES" << endl;
            return;
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





