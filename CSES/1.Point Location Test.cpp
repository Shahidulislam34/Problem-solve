#include<iostream>
using namespace std;
#define ll long long

struct point{
    ll x, y;
};

ll orientation(point a, point b, point c){
    ll ls= (c.x - a.x) * (a.y - b.y) - (c.y - a.y) * (a.x - b.x);
    if(ls==0)return 0;
    return ls>0?1:2;
}

void sol(){
    point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    ll val= orientation(a, b, c);
    if(val==0)cout << "TOUCH" << endl;
    else if(val==1)cout << "LEFT" << endl;
    else cout << "RIGHT" << endl;
}

int main(){
    ll t;cin>>t;
    while(t--){
        sol();
    }
    return 0;

}
