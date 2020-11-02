#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

#define inf -1e9

struct edge {
    int v, w, next;
} edge[200010];

int head[50010], tot;
int n, a, b, c, minLen, maxLen, dis[50010];
bool flag[50010];
queue<int> q;

void add(int x, int y, int w) {
    edge[tot].v = y;
    edge[tot].w = w;
    edge[tot].next = head[x];
    head[x] = tot;
    tot++;
}

void spfa() {
    while (!q.empty()) q.pop();
    for (int i = minLen; i <= maxLen; i++) {
        dis[i] = inf;
        flag[i] = 0;
    }
    dis[minLen - 1] = 0;
    flag[minLen - 1] = 1;
    q.push(minLen - 1);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        flag[x] = 0;
        for (int i = head[x]; i != -1; i = edge[i].next) {
            int y = edge[i].v;
            int w = edge[i].w;
            if (dis[y] < dis[x] + w) {
                dis[y] = dis[x] + w;
                if (!flag[y]) {
                    q.push(y);
                    flag[y] = 1;
                }
            }
        }
    }
}
int main() {
    cin.sync_with_stdio(false);
    while (cin >> n) {
        minLen = n;
        tot = 0;
        memset(head, -1, sizeof(head));

        for (int i = 0; i < n; i++) {
            cin >> a >> b >> c;
            add(a, b + 1, c);
            minLen = min(minLen, min(a, b));
            maxLen = max(maxLen, max(a, b));
        }
        minLen++;
        maxLen++;
        for (int i = minLen; i <= maxLen; i++) {
            add(i - 1, i, 0);
            add(i, i - 1, -1);
        }
        spfa();
        cout << dis[maxLen] << endl;
    }

    // system("pause");
    return 0;
}
