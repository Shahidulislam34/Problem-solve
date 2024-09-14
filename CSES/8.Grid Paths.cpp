#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=1e3, M=1e9+7;
int dp[N+5][N+5], n;
vector<string>v;

int ways(int i, int j){
    if(i==n && j==n && v[i][j]=='.'){dp[i][j]=1;return 1;}
    if(i>n || j>n || v[i][j]=='*')return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int mx=ways(i+1, j);
    mx=(1ll*(mx+ways(i, j+1)))%M;
    return dp[i][j]=mx;
}

int32_t main(){
    cin >> n;
    string str;
    v.push_back("0");
    for(int i=1; i<=n; ++i){
        cin >> str;
        str='0'+str;
        v.push_back(str);
    }

    memset(dp, -1, sizeof(dp));
    cout << ways(1, 1) << endl;
    return 0;
}
