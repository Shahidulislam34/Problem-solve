///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    str = '0' + str;
    set<int>res;
    for (int i = 1; i < n; ++i){
        int sum = 0, cur = 0;
        for (int j = 1; j <= n; ++j){
            if (i == j) cur = ((str[j] - '0') * 10 + (str[j + 1] - '0')), ++j;
            else cur = str[j] - '0';
            if (cur == 0){
                sum = 0;
                break;
            }
            else if (cur == 1 && sum == 0) sum += cur;
            else if (sum == 1) sum *= cur;
            else if (cur > 1) sum += cur;
        }
        res.insert(sum);
        if (sum == 0) break;
    }
    cout << *res.begin() << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}











