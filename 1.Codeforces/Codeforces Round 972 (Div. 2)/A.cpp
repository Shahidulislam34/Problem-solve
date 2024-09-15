#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

void sol(){
    int n;
    cin >> n;
    string res, str = "aeiou";
    vector<int>v(10, 0);

    for (int i = 1; i <= 5; ++i) v[i] = n / 5;
    for (int i = 1; i <= (n % 5); ++i) v[i] += 1;

    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= v[i]; ++j) {
            res.push_back(str[i - 1]);
        }
    }
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}



