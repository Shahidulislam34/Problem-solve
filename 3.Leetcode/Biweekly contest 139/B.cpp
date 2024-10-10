#include<bits/stdc++.h>
using namespace std;


int dis[50][50];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int row, col, m;
int grid[50][50];
bool exist(int r, int c) {
    if (r >= 0 && c >= 0 && r < row && c < col) return true;
    else return false;
}
void zero_one_bfs() {
    dis[0][0] = grid[0][0];
    deque<pair<int, int>>dq;
    dq.push_back({0, 0});
    while(!dq.empty()) {
        pair<int, int>pp = dq.front();
        int r = pp.first;
        int c = pp.second;
        dq.pop_front();
        cout << "rc:" << r << ' ' << c << endl;
        for (int i = 0; i < 4; ++i) {
            int x = r + dx[i], y = c + dy[i];
            cout << x << ' ' << y << endl;
            if (exist(x, y) && dis[x][y] > dis[r][c] + grid[x][y]) {
                dis[x][y] = dis[r][c] + grid[x][y];
                if (grid[x][y]) dq.push_back({x, y});
                else dq.push_front({x, y});
                cout << "x:" << x << ' ' << "y:" << y << endl;
            }
        }
    }

}

int main() {
        cin >> row >> col >> m;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                cin >> grid[i][j];
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j)
                dis[i][j] = INT_MAX;
        }

        zero_one_bfs();

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j)
                cout << dis[i][j] << ' ';
            cout << endl;
        }
        if (dis[row - 1][col - 1] < m) cout << "YES" << endl;
        else cout << "NO" << endl;
}
