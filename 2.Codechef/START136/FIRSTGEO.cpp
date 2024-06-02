#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int vis[50][50], res = 0;
string str;

bool out(int x, int y){
    if (x > 10 || x < -10 || y > 10 || y < -10) return false;
    else return true;
}
void dfs(int x, int y){
    if (vis[x + 10][y + 10] == 0) ++res;
    vis[x + 10][y + 10] = 1;
    for (int i = 0; i < 4; ++i){
        if (str[i] == '0') continue;
        x = x + dx[i];
        y = y + dy[i];
        if (out(x, y) && vis[x][y] == 0)
        dfs(x, y);
    }
}

void sol(){
    cin >> str;

    ///using dfs:
    dfs(0, 0);
    res = 0;
    vis[0 + 10][0 + 10] = 1;
    cout << res <<endl;

    ///using condition:
    /*
    int one = 0, two = 0, three = 0, four = 0;
    if (str[1] == '1' && str[2] == '1') one = 1;
    if (str[0] == '1' && str[2] == '1') two = 1;
    if (str[0] == '1' && str[3] == '1') three = 1;
    if (str[1] == '1' && str[3] == '1') four = 1;
    int res = 0, sum = one + two + three + four;
    if (sum == 0){
        for (int i = 0; i < 4; ++i) if (str[i] == '1') ++sum;
        if (sum == 1) res = 11;
        else if (sum == 2) res = 21;
    }
    else if (sum == 1)
        res = 121;
    else if (sum == 2)
        res = 231;
    else if (sum == 4)
        res = 441;
    cout << res << endl;*/
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int tt=1; cin >> tt;
    while(tt--)sol();
    return 0;
}






