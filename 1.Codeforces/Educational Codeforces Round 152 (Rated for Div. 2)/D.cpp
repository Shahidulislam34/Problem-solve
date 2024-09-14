#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define endl '\n'

void sol() {
	int n;
	cin >> n;
	vector<int>v(n + 5, 0);
	for (int i = 1; i <= n; ++i) cin >> v[i];

	int res = 0;
	vector<char>col(n + 5, 'B');
	col[0] = col[n + 1] = 'R';
	for (int i = 1; i <= n; ++i){
        if (col[i] == 'R' && v[i + 1] == 1) {
            col[i + 1] = 'R', --v[i + 1];
            continue;
        }
        else if (col[i] == 'R' && v[i + 1] == 2) {
            --res;
            continue;
        }
        if (col[i] == 'R') continue;
        if (v[i - 1] == 0 && v[i] > 0) --v[i], col[i] = col[i + 1] = 'R', ++res;
        else if (v[i - 1] == 0 && v[i] == 0 && v[i + 1] > 0) --v[i + 1], col[i] = col[i + 1] = 'R', ++res;
        else if (v[i - 1] == 0 && v[i] == 0 && v[i + 1] == 0) col[i] = 'R', ++res;
        else if (v[i - 1] > 0) col[i] = 'R';
	}
	cout << res << endl;
}

int32_t main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);

    sol();
    return 0;
}





