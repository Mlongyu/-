#include <cstring>
#include <iostream>
using namespace std;

int g[6][6];
bool visited[6][6];
struct point {
    int steps;//fangxiang
    int p[30];
    int x, y;
};
int startX = 0, startY = 0, endX = 4, endY = 4;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
point que[30], v, u, s;

void bfsPath() {
    s.x = startX;
    s.y = startY;
    s.steps = 0;
    s.p[s.steps] = 0;
    int f = 0, e = 0;
    que[e++] = s;
    visited[startX][startY] = true;
    while (f <= e) {
        u = que[f++];
        if (u.x == endX && u.y == endY) {/*arrive at the destiny*/
            int xx = 0, yy = 0;
            cout << "(" << xx << ", " << yy << ")\n";
            for (int i = 1; i <= u.steps; i++) {
                xx = xx + dx[u.p[i]];
                yy = yy + dy[u.p[i]];
                cout << "(" << xx << ", " << yy << ")\n";
            }
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = u.x + dx[i];
            int ny = u.y + dy[i];
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && g[nx][ny] != 1 &&
                !visited[nx][ny]) {/*不出界且未走过*/
                v.x = nx;
                v.y = ny;
                v.steps = u.steps + 1;
                for (int j = 0; j < u.steps; ++j) {
                    v.p[j] = u.p[j];
                }
                v.p[v.steps] = i;
                que[e++] = v;
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    int m = 5, n = 5;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    bfsPath();
    //system("pause");
    return 0;
}