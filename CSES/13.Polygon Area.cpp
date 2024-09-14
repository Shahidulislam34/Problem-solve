#include<iostream>
#include<vector>
#define int long long
using namespace std;

struct point{
    int x, y;
};

int orientation(point a, point b, point c){
    return (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
}

void sol(){
    int n;
    cin >> n;
    vector<point>v(n+5);
    for(int i=1; i<=n; ++i){
        cin >> v[i].x >> v[i].y;
    }
    int area=0;
    for(int i=2; i<=n-1; ++i){
        area+=orientation(v[1], v[i], v[i+1]);
    }
    cout << abs(area) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    sol();
    return 0;
}
