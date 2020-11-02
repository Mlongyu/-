#include <iostream>
using namespace std;

int n, a[101], ans;  //不能放在fun函数后面
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
bool map[500][500], visited[500][500][101][8];
/*x,y表示当前位置，curTime是当前分裂次数，direction是分裂的方向。*/
void fun(int x, int y, int curTime, int dirction) {
    if (curTime > n || visited[x][y][curTime][dirction]) return;
    visited[x][y][curTime][dirction] = 1;
    for (int i = 1; i <= a[curTime]; i++) {
        x += dx[dirction];
        y += dy[dirction];
        if (!map[x][y]) {
            map[x][y] = 1;
            ans++;
        }
    }
    fun(x, y, curTime + 1, (dirction + 7) % 8);
    fun(x, y, curTime + 1, (dirction + 1) % 8);
}

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; i++) cin >> a[i];
        fun(250, 250, 1, 0);
        cout << ans << endl;
    }

    return 0;
}