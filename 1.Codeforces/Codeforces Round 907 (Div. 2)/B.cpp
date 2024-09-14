///accepted
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void sol()
{
    ll n,q;cin>>n>>q;
    vector<ll>v(n+5),x(q+5);
    for(ll i=1;i<=n;++i)cin>>v[i];
    for(ll i=1;i<=q;++i)cin>>x[i];

    vector<bool>div(40,false);

    ll c=1;
    for(ll i=2;i<=(1<<30);i*=2)
    {
        for(ll j=1;j<=n;++j)
        {
            if(v[j]%i==0)
            {
                div[c]=true;break;
            }
        }
        ++c;
    }
//    for(ll i=1;i<=30;++i)cout<<div[i]<<' ';cout<<endl;
    ll ind=-1;
    for(ll i=1;i<=q;++i)
    {
        if(div[x[i]]==true){ind=i;break;}
    }

    if(ind==-1)
    {
//        cout<<"SHOUROV"<<endl;
        for(ll i=1;i<=n;++i)cout<<v[i]<<' ';cout<<endl;
    }
    else
    {

        ll mx=x[ind];
        vector<ll>st;
        st.push_back(mx);
//        cout<<mx<<' ';
        for(ll i=ind+1;i<=q;++i)
        {
            if(x[i]<mx)
            {
                mx=x[i];
                st.push_back(mx);
            }
        }
//        cout<<mx<<endl;
        ll sz=st.size();
        for(ll i=0;i<sz;++i)
        {
            ll add=1<<(st[i]-1);
            ll mod=1<<(st[i]);
            for(ll j=1;j<=n;++j)
            {
                if(v[j]%mod==0)v[j]+=add;
            }
        }
//        cout<<"SZ:"<<sz<<endl;
//        for(ll i=0;i<sz;++i)cout<<st[i]<<' ';cout<<endl;
        for(ll i=1;i<=n;++i)cout<<v[i]<<' ';cout<<endl;
    }



}

int main()
{
    faster();
    ll t=1;cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}

