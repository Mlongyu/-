#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int inf = 0x3f3f3f3f;
int n, s, e, m, k;
priority_queue<pair<int, int>> q;
bool vis[10001];
int path[10001];
int dis1[10001], dis2[10001];
int fre1[10001], fre2[10001];

struct edge {
    int to, next, w;
} edge[10001];

int head[10001], tot;

void dij(int s, int *dis, int *fre) {
    while (q.size()) q.pop();
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        dis[i] = inf;
    }
    fre[s] = -1;
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = head[x]; i != -1; i = edge[i].next) {
            int y = edge[i].to, w = edge[i].w;
            if (dis[y] > dis[x] + w) {
                dis[y] = dis[x] + w;
                fre[y] = x;
                q.push(make_pair(-dis[y], y));
            }
        }
    }
}

int main() {
    int ct = 0;
    ios::sync_with_stdio(false);
    while (cin >> n >> s >> e) {
        if (ct) cout << endl;
        cin >> m;
        tot = 0;
        int a, b, c;
        // init
        tot = 0;
        memset(head, -1, sizeof(head));
        while (m--) {
            cin >> a >> b >> c;
            edge[tot].to = b;
            edge[tot].next = head[a];
            edge[tot].w = c;
            head[a] = tot;
            tot++;
            edge[tot].to = a;
            edge[tot].next = head[b];
            edge[tot].w = c;
            head[b] = tot;
            tot++;
        }

        dij(s, dis1, fre1);
        dij(e, dis2, fre2);

        int u, v, w;
        cin >> k;
        int ans = dis1[e], minu, minv, flag = 0;
        for (int i = 0; i < k; i++) {
            cin >> u >> v >> w;
            if (dis1[u] + dis2[v] + w < ans) {
                ans = dis1[u] + dis2[v] + w;
                minu = u;
                minv = v;
                flag = 1;
            }
            if (dis1[v] + dis2[u] + w < ans) {
                ans = dis1[v] + dis2[u] + w;
                minu = v;
                minv = u;
                flag = 1;
            }
        }
        if (flag == 1) {
            int cnt = 0;
            int temp = minu;
            path[cnt++] = temp;
            while (fre1[temp] != -1) {
                path[cnt++] = fre1[temp];
                temp = fre1[temp];
            }
            for (int i = cnt - 1; i >= 0; i--) cout << path[i] << " ";
            cnt = 0;
            temp = minv;
            path[cnt++] = temp;
            while (fre2[temp] != -1) {
                path[cnt++] = fre2[temp];
                temp = fre2[temp];
            }
            for (int i = 0; i < cnt - 1; i++) cout << path[i] << " ";
            cout << path[cnt - 1] << endl;
            cout << minu << endl;
        } else {
            int cnt = 0;
            int temp = e;
            path[cnt++] = temp;
            while (fre1[temp] != -1) {
                path[cnt++] = fre1[temp];
                temp = fre1[temp];
            }
            for (int i = cnt - 1; i > 0; i--) cout << path[i] << " ";
            cout << path[0] << endl;
            cout << "Ticket Not Used" << endl;
        }
        cout << ans << endl;
        ct++;
    }

    return 0;
}
