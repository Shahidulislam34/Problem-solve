#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int B1 = 283, B2 = 293, M1 = 1e9 + 87, M2 = 1e9 + 93, N = 2e5;
pair<int, int>PRE1[N + 5], PRE2[N + 5], POW[N + 5], IPOW[N + 5];
int le;

int big_mod(int base, int power, int mod){
    int res = 1;
    while (power != 0){
        if (power % 2 == 0) base = (1LL * base * base) % mod, power /= 2;
        else res = (1LL * res * base) % mod, --power;
    }
    return res;
}

void prec_hash(){
    POW[0] = {1, 1};
    for (int i = 1; i <= N; ++i){
        POW[i].first = (1LL * POW[i - 1].first * B1) % M1;
        POW[i].second = (1LL * POW[i - 1].second * B2) % M2;
    }
    int ip1 = big_mod(B1, M1 - 2, M1);
    int ip2 = big_mod(B2, M2 - 2, M2);
    IPOW[0] = {1, 1};
    for (int i = 1; i <= N; ++i){
        IPOW[i].first = (1LL * IPOW[i - 1].first * ip1) % M1;
        IPOW[i].second = (1LL * IPOW[i - 1].second * ip2) % M2;
    }
}

void init_hash1(string str){
    PRE1[0] = {str[0] - '0', str[0] - '0'};
    int ZZ = str.size();
    for (int i = 1; i < ZZ; ++i){
        PRE1[i].first = PRE1[i - 1].first + (1LL * (str[i] - '0') * POW[i].first) % M1;
        PRE1[i].first %= M1;
        PRE1[i].second = PRE1[i - 1].second + (1LL * (str[i] - '0') * POW[i].second) % M2;
        PRE1[i].second %= M2;
    }
}

pair<int, int> get_hash1(int l, int r){
    pair<int, int>res;
    res.first = PRE1[r].first;
    if (l) res.first = (1LL * (res.first - PRE1[l - 1].first + M1) * (IPOW[l].first)) % M1;
    res.second = PRE1[r].second;
    if (l) res.second = (1LL * (res.second - PRE1[l - 1].second + M2) * (IPOW[l].second)) % M2;
    return res;
}

void init_hash2(string str){
    PRE2[0] = {str[0] - '0', str[0] - '0'};
    int ZZ = str.size();
    for (int i = 1; i < ZZ; ++i){
        PRE2[i].first = PRE2[i - 1].first + (1LL * (str[i] - '0') * POW[i].first) % M1;
        PRE2[i].first %= M1;
        PRE2[i].second = PRE2[i - 1].second + (1LL * (str[i] - '0') * POW[i].second) % M2;
        PRE2[i].second %= M2;
    }
}

pair<int, int> get_hash2(int l, int r){
    pair<int, int>res;
    res.first = PRE2[r].first;
    if (l) res.first = (1LL * (res.first - PRE2[l - 1].first + M1) * (IPOW[l].first)) % M1;
    res.second = PRE2[r].second;
    if (l) res.second = (1LL * (res.second - PRE2[l - 1].second + M2) * (IPOW[l].second)) % M2;
    return res;
}

void sol(){
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    init_hash1(str);
    string one;
    for (int i = 1; i <= n; ++i) one.push_back('1');
    init_hash2(one);
    int cnt[n];
    memset(cnt , 0, sizeof(cnt));
    if (str[0] == '1') cnt[0] = 1;
    for (int i = 1; i < n; ++i){
        cnt[i] += cnt[i - 1] + (str[i] - '0');
    }

    map<pair<int, int>, int>mp;
    pair<int, int>pp1, pp2, pp3;
    int sing, num, a, b;
    for (int i = 1; i <= m; ++i){
        cin >> a >> b;
        pp1 = pp2 = pp3 = {0, 0};
        sing = cnt[b - 1];
        if (a > 1) sing -= cnt[a - 2];

        if (a > 1)
            pp1 = get_hash1(0, a - 2);
        if (b < n)
            pp3 = get_hash1(b, n - 1);
        if (sing > 0)
            pp2 = get_hash2(0, sing - 1);

        num = b - a + 1 - sing + a - 1;
        pp2.first = (1LL * POW[num].first * pp2.first) % M1;
        pp2.second = (1LL * POW[num].second * pp2.second) % M2;
        pp3.first = (1LL * POW[b].first * pp3.first) % M1;
        pp3.second = (1LL * POW[b].second * pp3.second) % M2;
        pp1.first = (1LL * pp1.first + 1LL * pp2.first + 1LL * pp3.first) % M1;
        pp1.second = (1LL * pp1.second + 1LL * pp2.second + 1LL * pp3.second) % M2;
        ++mp[pp1];
    }
    cout << mp.size() << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    prec_hash();

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}







