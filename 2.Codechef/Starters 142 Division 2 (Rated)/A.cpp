#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define endl '\n'

void sol() {
	int n, m;
	cin >> n >> m;
	int ans = n * m / 4 * 6;
	if (n >= 4 && m >= 4) {
		ans = n * m / 2 * 2 + 4;
	}
	cout << ans << endl;
}

int32_t main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}




