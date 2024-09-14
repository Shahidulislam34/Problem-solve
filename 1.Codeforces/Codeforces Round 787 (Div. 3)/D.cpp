///accepted
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define vll vector<ll>
#define vin() for(ll i=1;i<=n;++i)cin>>v[i];
#define v2in() for(ll i=1;i<=n;++i)cin>>v2[i];
#define v3in() for(ll i=1;i<=n;++i)cin>>v3[i];
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<ll>tree[200005];
vector<ll>ans;
vector<bool>bul(200005,0);
ll sqrt_floor(ll n)
{
    ll l,r,mid,ans=1;
    l=1;r=min((ll)1e9,n);
    while(l<=r)
    {
        mid=(l+r)/2;
        if(mid*mid<=n){ans=mid;l=mid+1;}
        else r=mid-1;
    }return ans;
}
ll sqrt_ceil(ll n)
{
    ll l,r,mid,ans=1;
    l=1;r=min((ll)1e9,n);
    while(l<=r)
    {
        mid=(l+r)/2;
        if(mid*mid>=n){ans=mid;r=mid-1;}
        else l=mid+1;
    }return ans;
}

void omg(ll node)
{
    ans.pb(node);
//    cout<<"Shourov"<<endl;
    bul[node]=1;
    ll flag=0;
    for(auto x:tree[node])
    {
        if(bul[x]==0)
        {
            flag=1;
            omg(x);
        }
    }
    if(flag==0)ans.pb(0);
}

void sol()
{
    ll n;cin>>n;
    vector<ll>v(n+5);
    for(ll i=1;i<=n;++i)cin>>v[i];
    ll root;
    for(ll i=1;i<=n;++i)tree[i].clear();
    fill(bul.begin(),bul.begin()+n+1,false);
    ans.clear();
    for(ll i=1;i<=n;++i)
    {
        if(v[i]!=i)
        {
            tree[i].pb(v[i]);
            tree[v[i]].pb(i);
        }
        else root=i;
    }
    omg(root);
    ll res=0,m=ans.size(),l,r;
    vector<pair<ll,ll>>fol;
    l=-1;
//    for(ll i=0;i<ans.size();++i)cout<<ans[i]<<' ';cout<<endl;
    for(ll i=0;i<m;++i)
    {
        if(l==-1&&ans[i]!=0)l=i;
        if(ans[i]!=0)r=i;
        else if(ans[i]==0){fol.pb({l,r});l=-1;}
    }
    cout<<fol.size()<<endl;
    for(auto x:fol)
    {
        cout<<x.ss-x.ff+1<<endl;
        for(ll i=x.ff;i<=x.ss;++i)cout<<ans[i]<<' ';cout<<endl;
    }
    cout<<endl;

}

int main()
{
    faster();
    ll t=1;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}






