#include<bits/stdc++.h>
using namespace std;

void sol() {
    int r, c, n;
    cin >> r >> c >> n;
    vector<pair<int, int>>v(n + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    v[0] = {-1, -1};
    sort(v.begin() + 1, v.begin() + n + 1);

    vector<int>tmp;
    vector<int>pre(n + 5, -1);
    tmp.push_back(-1);
    int ind = 0;
    for (int i = 1; i <= n; ++i) {
        auto it = upper_bound(tmp.begin(), tmp.end(), v[i].second);
        if (it == tmp.end()) {
            tmp.push_back(v[i].second);
            ++ind;
            pre[i] = ind;
        }
        else {
            int plc = it - tmp.begin();
            tmp[plc] = v[i].second;
            pre[i] = plc;
        }
    }

    int len = ind;
    vector<pair<int, int>>seq;
    seq.push_back({r, c});
    for (int i = n; i >= 1; --i) {
        if (pre[i] == ind) {
            seq.push_back(v[i]);
            --ind;
        }
    }
    seq.push_back({1, 1});
    reverse(seq.begin(), seq.end());

    string str;
    for (int i = 1; i < len + 2; ++i) {
        int down = abs(seq[i].first - seq[i - 1].first);
        int right = abs(seq[i].second - seq[i - 1].second);
        for (int j = 1; j <= down; ++j) str.push_back('D');
        for (int j = 1; j <= right; ++j) str.push_back('R');
    }
    cout << len << endl;
    cout << str << endl;
}

int main() {
    sol();
    return 0;
}
