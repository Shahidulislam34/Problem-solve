#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, k, inc;
    cin >> n >> k;

    if (n % 2 == 1) inc = 2;
    else inc = 1;
    int sum = 0;
    for (int i = 1; i <= n / 2; ++i) sum += inc, inc += 2;
    sum *= 2;
    if ((k % 2 == 1) || k > sum){
        cout << "No" << endl;
        return;
    }
    sum = k;
    vector<int>res(n + 5);
    for (int i = 1; i <= n; ++i) res[i] = i;
    int a, b;
    a = 1, b = n;
    while(a <= b && sum > 0){
        if (a + (sum / 2) >= b){
            res[a] = b;
            res[b] = a;
            sum -= (2 * abs(a - b));
            ++a;
            --b;
        }
        else {
            res[a] = sum / 2 + a;
            res[sum / 2 + a] = a;
            break;
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; ++i) cout << res[i] << ' '; cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}






