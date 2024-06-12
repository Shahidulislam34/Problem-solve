#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n;
    string str;
    cin >> str;
    n = str.size();
    str = '0' + str;
    int carry = 0;
    for (int i = n; i >= 1; --i){
        int dec = str[i] - '0';
        if (dec - carry < 0 || dec - carry == 9){
            cout << "NO" << endl;
            return;
        }
        carry = 1;
    }
    if (str[1] != '1') {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}
