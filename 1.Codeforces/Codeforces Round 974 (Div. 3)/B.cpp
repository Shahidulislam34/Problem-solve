#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);


void sol(){
    int n, k;
    cin >> n >> k;
    int a = max(1ll, n - k + 1), b = n;
    int odd = (b - a + 1) / 2;
    if (a % 2 == 1 && b % 2 == 1) ++odd;
    if (odd % 2) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}




