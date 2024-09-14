#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e6, M=1e9+7;
int dp[N+5];
vector<int>v(N+5);
int n, m;

int ways(int x){
    if(dp[x]!=-1)return dp[x];
    if(x==0)return 1;
    if(x<v[1])return M;
    int sum=0, ok=0;
    for(int i=1; i<=n && x>=v[i]; ++i){
        int val=ways(x-v[i]);
        if(val!=M){
            sum=(1ll*(sum+val))%M;
            ok=1;
        }
    }
    if(ok)return dp[x]=sum;
    else return dp[x]=M;
}

int32_t main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i)cin >> v[i];
    memset(dp, -1, sizeof(dp));
    sort(v.begin()+1, v.begin()+n+1);
    int val=ways(m);
    if(val==M)val=0;
    cout << val << endl;
    return 0;
}
