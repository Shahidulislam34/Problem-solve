///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n;
    cin >>  n;
    string str;
    cin >> str;
    str = '0' + str;
    int ex = 0;
    for (int i = 2; i <= n; ++i){
        if (str[i] >= '0' && str[i] <= '9' && str[i - 1] >= 'a' && str[i - 1] <= 'z')
        {
            cout << "NO" << endl;
            return;
        }
        if (str[i] > 'z' || (str[i] < 'a' && str[i] > '9') || (str[i] < '0')){
            cout << "NO" << endl;
            return;
        }
    }
    string dig, cha;
    for (int i = 1; i <= n; ++i){
        if (str[i] >= '0' && str[i] <= '9') dig.push_back(str[i]);
        else if(str[i] >= 'a' && str[i] <= 'z') cha.push_back(str[i]);
    }
    string cdig, ccha;
    cdig = dig;
    ccha = cha;
    sort(dig.begin(), dig.end());
    sort(cha.begin(), cha.end());
    if (cdig != dig || cha != ccha){
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}

