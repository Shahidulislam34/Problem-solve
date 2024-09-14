#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
const int N=1e6;
int dp[N+5];

int recur(int x){
    if(x==0)return 0;
    if(x<=9)return 1;
    if(dp[x]!=-1)return dp[x];
    int m=x, mn=INT_MAX;
    while(m){
        if(m%10!=0){
            mn=min(mn, recur(x-(m%10))+1);
        }
        m/=10;
    }
    return dp[x]=mn;
}

int32_t main(){
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << recur(n) << endl;
    return 0;
}
