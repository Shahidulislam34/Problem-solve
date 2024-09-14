#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define float long double
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define tc() int tt=1;cin >> tt; while(tt--)sol();
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int M=1e9+7;

int sqrt_floor(int n){
    int l,r,mid,ans=1;
    l=1;r=min((int)1e9,n);
    while(l<=r){
        mid=(l+r)/2;
        if(mid*mid<=n){ans=mid;l=mid+1;}
        else r=mid-1;
    }return ans;
}
int sqrt_ceil(int n){
    int l,r,mid,ans=1;
    l=1;r=min((int)1e9,n);
    while(l<=r){
        mid=(l+r)/2;
        if(mid*mid>=n){ans=mid;r=mid-1;}
        else l=mid+1;
    }return ans;
}
int bit[61+5];
void bit_cal(){
    int m=1;
    for(int i=0;i<62;++i){
        bit[i]=m;
        m=(int)m*2;
    }
}
int dig_cnt(int n){
    int ans=0;
    while(n){
        ++ans;
        n/=10;
    }return ans;
}
int dig_sum(int n){
    int ans=0;
    while(n){
        ans+=(n%10);
        n/=10;
    }return ans;
}

void sol(){
    int n, q;
    cin >> n >>q;
    vector<int>v(n+5),pre(n+5,0);
    for(int i=1;i<=n;++i)cin>>v[i];
    for(int i=1;i<=n;++i){
        pre[i]=pre[i-1]+v[i];
    }

    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<pre[b]-pre[a-1]<<endl;
    }
}

int32_t main(){
    faster();
    sol();
    return 0;
}


