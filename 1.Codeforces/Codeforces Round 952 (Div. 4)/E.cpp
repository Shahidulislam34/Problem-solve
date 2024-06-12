///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    int res = 0, tmp = k;
    for (int i = 1; i <= x; ++i){
        tmp = k;
        if (tmp % i == 0){
            tmp /= i;
            for (int j = 1; j <= y; ++j){
                if (tmp % j == 0){
                    int tmp2 = tmp / j;

                    if (tmp2 <= z){
                        int a,b, c;
                        a = x - i + 1;
                        b = y - j + 1;
                        c = z - tmp2 + 1;
                        res = max(res, (a * b * c));
                    }
                }
            }
        }
    }
    cout << res << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}








