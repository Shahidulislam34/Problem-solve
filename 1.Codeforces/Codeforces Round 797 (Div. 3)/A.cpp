///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    int a , b, c;
    a = n / 3;
    b = n / 3;
    c = n / 3;
    if (n % 3 == 0){
        --a;
        ++c;
    }
    else if (n % 3 == 1){
        c += 2;
        --a;
    }
    else {
        ++b;
        --a;
        c += 2;
    }
    cout << b << ' ' << c << ' ' << a << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}

