#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

void sol(){
    string str;
    cin >> str;
    int n = str.size();
    int ind = n;
    for (int i = 1; i < n; ++i) {
        if (str[i] == str[i - 1]) {
            ind = i;
            break;
        }
    }
    char ch = str[ind - 1];
    if (ch == 'z') ch = 'a';
    else ++ch;
    str.insert(str.begin() + ind, ch);
    cout << str << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}


