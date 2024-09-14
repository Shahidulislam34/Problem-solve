#include<iostream>
#define int long long
using namespace std;

struct point{
    int x, y;
};

int orientation(point a, point b, point c){
    int val=(a.x * b.y + b.x * c.y + c.x * a.y)-
            (a.y * b.x + b.y * c.x + c.y * a.x);
    if(val==0)return 0;
    else if(val<0)return -1;
    else return 1;
}

bool onsegment(point a, point b, point c){
    if(c.x >= min(a.x , b.x) && c.x <= max(a.x, b.x) && c.y >= min(a.y, b.y) && c.y<=max(a.y, b.y))
        return true;
    else
        return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    point arr[n+5];
    for(int i=1; i<=n; ++i){
        cin >> arr[i].x >> arr[i].y;
    }
    point p, q, a, b;
    q.x=1e9+5,q.y=1e9+5;
    arr[n+1]=arr[1];
    while(m--){
        cin >> p.x >> p.y;
        int ints=0, flag=0, cnt=0;
        for(int i=1; i<=n; ++i){
            a=arr[i],b=arr[i+1];
            int abp=orientation(a, b, p);
            if(abp==0 && onsegment(a, b, p)==true){
                cout << "BOUNDARY" << endl;
                flag=1;
                break;
            }
            int abq=orientation(a, b, q);
            int pqa=orientation(p, q, a);
            int pqb=orientation(p, q, b);
            if(abp+abq==0 && pqa+pqb==0)++ints;
            else if(pqa==0 && pqb==0 && onsegment(p, q, a))--ints;
            else if((a.x-p.x)*(p.y-q.y)==(a.y-p.y)*(p.x-q.x) && onsegment(p, q, a))++ints;
        }
//        cout << ints << ' ' << cnt << endl;
        if(flag==1)continue;
        if(ints%2==1)cout << "INSIDE" << endl;
        else cout << "OUTSIDE" << endl;
    }
    return 0;
}
