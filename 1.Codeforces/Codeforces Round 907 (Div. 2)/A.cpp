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
    ll n,flag=0;cin>>n;
    vector<ll>v(n+5);
    for(ll i=1;i<=n;++i)cin>>v[i];

    for(ll i=1;i<=n;i=i*2)
    {
        for(ll j=i+2;j<=2*i&&j<=n;++j)
        {
            if(v[j-1]>v[j])
            {
                flag=1;break;
            }
        }
        if(flag==1)break;
    }
    ll mul=1;
    while(mul<=n)mul*=2;
    mul/=2;
    for(ll i=mul+2;i<=n;++i)if(v[i-1]>v[i]){flag=1;break;}
    if(flag==1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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


