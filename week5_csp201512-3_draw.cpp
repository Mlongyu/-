#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int m, n, q;
char map[102][102];
bool visited0[102][102];
bool visited1[102][102];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
struct point {
    int x_;
    int y_;
};
queue<point> que;
void bfs(int x, int y, char c) {
    memset(visited1, 0, sizeof(visited1));
    //起始位置
    point p;
    p.x_ = x;
    p.y_ = y;
    visited1[x][y] = true;
    map[x][y] = c;
    que.push(p);
    while (!que.empty()) {
        point cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            point _new;
            int _x = cur.x_ + dx[i];
            int _y = cur.y_ + dy[i];
            if (visited1[_x][_y] == false && visited0[_x][_y] == false &&
                _x >= 0 && _x < m && _y >= 0 && _y < n) {
                visited1[_x][_y] = true;
                _new.x_ = _x;
                _new.y_ = _y;
                map[_x][_y] = c;
                que.push(_new);
            }
        }
    }
}

int main() {
    while (cin >> m >> n >> q) {
        int op, x1, y1, x2, y2, x, y;
        char c;
        memset(visited0, 0, sizeof(visited0));
        //初始化画图区域
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) map[i][j] = '.';
        for (int i = 0; i < q; i++) {
            cin >> op;
            if (op == 0) {  //画线段
                cin >> x1 >> y1 >> x2 >> y2;
                if (x1 == x2) {  //画竖线
                    if (y1 > y2) {
                        int t = y1;
                        y1 = y2;
                        y2 = t;
                    }
                    for (int k = y1; k <= y2; k++) {
                        if (visited0[x1][k] == false) {  //没有画过线段
                            visited0[x1][k] = true;
                            map[x1][k] = '|';
                        } else if (map[x1][k] == '-')
                            map[x1][k] = '+';
                    }
                } else {
                    if (x1 > x2) {
                        int t = x1;
                        x1 = x2;
                        x2 = t;
                    }
                    for (int k = x1; k <= x2; k++) {
                        if (visited0[k][y1] == false) {  //没有画过线段
                            visited0[k][y1] = true;
                            map[k][y1] = '-';
                        } else if (map[k][y1] == '|')
                            map[k][y1] = '+';
                    }
                }
            } else {                 //填充
                cin >> x >> y >> c;  //起始位置是x,y
                bfs(x, y, c);
            }
        }
        for (int j = n - 1; j >= 0; j--) {  //输出
            for (int i = 0; i < m; i++) {
                cout << map[i][j];
            }
            cout << endl;
        }
    }
    // system("pause");
    return 0;
}
