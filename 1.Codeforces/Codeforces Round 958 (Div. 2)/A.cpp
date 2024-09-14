///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, k;
    cin >> n >> k;
    int sum = 0;
    while(n > 1) {
        if (n <= k) {
            ++sum; break;
        }
        sum += (n / k);
        n = (n / k) + (n % k);
    }
    cout << sum << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}




