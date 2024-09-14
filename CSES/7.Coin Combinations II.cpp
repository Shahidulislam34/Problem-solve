#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int N=2e5, M=1e9+7;
int n, m;
int dp[1000000+1][100+1];
vector<int>v(N+5);

int ways(int val, int i){
    if(val<0)return 0;
    else if(val==0)return 1;
    if(dp[val][i]!=-1)return dp[val][i];
    int sum=0;
    for(int k=i; k<=n; ++k){
        sum=((long long)(sum+ways(val-v[k], k)))%M;
    }
    return dp[val][i]=sum;
}

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i)cin >> v[i];
    sort(v.begin()+1, v.begin()+n+1);
    memset(dp, -1, sizeof(dp));
    cout << ways(m, 1) << endl;
    return 0;
}
