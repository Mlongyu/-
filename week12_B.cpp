#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, z, f;
} a;

int r, l, c, sx, sy, sz;
char mp[31][31][31];
bool flag[31][31][31];
queue<node> q;

int dx[7] = {0, 0, 0, 0, 0, 1, -1};
int dy[7] = {0, 0, 0, 1, -1, 0, 0};
int dz[7] = {0, 1, -1, 0, 0, 0, 0};

int bfs() {
    memset(flag, 0, sizeof(flag));
    while (!q.empty()) q.pop();
    int ans = 0;
    if (mp[sx][sy][sz] == 'E') return ans;
    node a;
    a.x = sx;
    a.y = sy;
    a.z = sz;
    a.f = 0;
    q.push(a);
    flag[a.x][a.y][a.z] = 1;
    while (!q.empty()) {
        a = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            int x = a.x + dx[i];
            int y = a.y + dy[i];
            int z = a.z + dz[i];
            if (x >= 1 && x <= l && y >= 1 && y <= r && z >= 1 && z <= c &&
                !flag[x][y][z] && (mp[x][y][z] == '.' || mp[x][y][z] == 'E')) {
                if (mp[x][y][z] == 'E') {
                    return a.f + 1;
                }
                node tmp;
                tmp.x = x;
                tmp.y = y;
                tmp.z = z;
                tmp.f = a.f + 1;
                flag[x][y][z] = 1;
                q.push(tmp);
            }
        }
    }
    return -1;
}
int main() {
        while (cin >> l >> r >> c) {
        char s[31];
        if (l == 0 && r == 0 && c == 0) break;
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= r; j++) {
                cin >> s;
                for (int k = 0; k < c; k++) {
                    mp[i][j][k + 1] = s[k];
                    if (s[k] == 'S') sx = i, sy = j, sz = k + 1;
                }
            }
        }
        int ans = bfs();
        if (ans == -1)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << ans << " minute(s)." << endl;
    }
    return 0;
}