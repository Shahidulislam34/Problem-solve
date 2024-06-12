///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    string a, b;
    cin >> a >> b;
    char c1 = a[0], c2 = b[0];
    a[0] = b[0];
    b[0] = c1;
    cout << a << ' ' << b << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}





