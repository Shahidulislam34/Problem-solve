#include<iostream>
#include<cstring>
#define endl '\n'
using namespace std;
int n, x;
int dp[1005][100005];
int price[1005], page[1005];

int dyn(int ci, int pp){
    if(ci==n+1)return 0;
    if(dp[ci][pp]!=-1)return dp[ci][pp];
    int mx=dyn(ci+1, pp);
    if(price[ci]+pp<=x){
        mx=max(mx, dyn(ci+1, price[ci]+pp)+page[ci]);
    }
    return dp[ci][pp]=mx;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> x;
    for(int i=1; i<=n; ++i)cin >> price[i];
    for(int i=1; i<=n; ++i)cin >> page[i];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=x; ++j){
            if(j>=price[i]){
                int baki=j-price[i];
                int pg=dp[i-1][baki]+page[i];
                dp[i][j]=max(pg, dp[i-1][j]);
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}
