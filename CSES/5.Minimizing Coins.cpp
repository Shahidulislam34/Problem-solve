#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int N=1e6, M=1e9+7;
int dp[N+5];
vector<int>v(N+5);
int n, m;
map<int,int>mp;

int min_num(int x){
    if(dp[x]!=-1)return dp[x];
    if(x==0)return 0;
    if(x<v[1])return M;

    int mn=M;
    for(int i=1; i<=n && x>=v[i]; ++i){
        int val=min_num(x-v[i]);
        if(val!=M){
            mn=min(mn, val+1);
        }
    }
    return dp[x]=mn;
}

int32_t main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i)cin >> v[i],mp[v[i]]=1;
    memset(dp, -1, sizeof(dp));
    sort(v.begin()+1, v.begin()+n+1);
    int res=min_num(m);
    if(res==M)res=-1;
    cout << res << endl;
    return 0;
}
