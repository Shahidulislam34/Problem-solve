///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    int sum = 0;
    while(n) sum += (n % 10), n /= 10;
    cout << sum << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}

