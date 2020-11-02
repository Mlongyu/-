#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int t, n, m;
const int inf = 0x3f3f3f3f;

int inDegree[5010];
int support[5010];

int vis[5010], cmp[5010], pre[5010], low[5010], sz[5010], dfs_ct, k;
vector<int> G[5010], rG[5010];
stack<int> s;

void dfs(int u) {
    pre[u] = low[u] = ++dfs_ct;
    s.push(u);
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!pre[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (!cmp[v])
            low[u] = min(low[u], low[v]);
    }
    if (pre[u] == low[u]) {
        k++;
        for (;;) {
            int x = s.top();
            s.pop();
            cmp[x] = k;  //记录每个点所在的连通分量编号
            sz[k]++;
            if (x == u) break;
        }
    }
}

int dfs1(int u) {
    int ans = sz[u];
    vis[u] = true;

    for (int i = 0; i < rG[u].size(); i++) {
        int v = rG[u][i];
        if (vis[v]) continue;
        ans += dfs1(v);
    }
    return ans;
}



int main() {
    cin.sync_with_stdio(false);

    cin >> t;
    for (int ca = 1; ca <= t; ca++) {
        cin >> n >> m;
        for (int i = 0; i <= n; i++) {
            G[i].clear();
            rG[i].clear();
        }

        int x, y;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            G[x].push_back(y);
        }

        dfs_ct = k = 0;
        memset(pre, 0, sizeof(pre));
        memset(cmp, 0, sizeof(cmp));
        memset(sz, 0, sizeof(sz));

        for (int i = 0; i < n; i++) {
            if (pre[i] == 0) dfs(i);
        }
        memset(inDegree, 0, sizeof(inDegree));

        // suodian
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < G[i].size(); j++) {
                int u = cmp[i], v = cmp[G[i][j]];
                if (u == v) continue;
                inDegree[u]++;
                rG[v].push_back(u);
            }
        }

        int mx = 0;
        for (int i = 1; i <= k; i++) {
            if (inDegree[i] == 0) {
                memset(vis, 0, sizeof(vis));
                support[i] = dfs1(i);
                mx = max(mx, support[i]);
            }
        }
        cout << "Case " << ca << ": " << mx - 1 << endl;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            int u = cmp[i];
            if (inDegree[u] == 0 && support[u] == mx) {
                if (flag) cout << " ";
                cout << i;
                flag = true;
            }
        }
        cout << endl;
    }
    return 0;
}
