#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M = 1e9 + 7;
const int N = 2e5;

int big_mod(int base, int power, int mod){
    int res = 1;
    while (power != 0){
        if (power % 2 == 0) base = (1LL * base * base) % mod, power /= 2;
        else res = (1LL * res * base) % mod, --power;
    }
    return res;
}

void sol(){

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}




