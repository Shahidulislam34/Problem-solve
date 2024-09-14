#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100, M=1e9+7;
int n, m;
vector<int>v(N+5);

int ways(int x, int val){
    if(x==0)return 1;
    int sum=0;
    for(int i=1; i<=n && x>=v[i]; ++i){
        if(val<=v[i])
            sum=(1ll*(sum+ways(x-v[i], v[i])))%M;
    }
    return sum;
}

int32_t main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i)cin >> v[i];
    sort(v.begin()+1, v.begin()+n+1);
    cout << ways(m, v[1]) << endl;
    return 0;
}
