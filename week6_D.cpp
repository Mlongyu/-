#include <algorithm>
#include <iostream>
using namespace std;
int u, v, w;
int root, total, n, m;
struct edge {
    int u, v, w;
    bool operator<(edge &e) { return w < e.w; }
};
edge e[200001];
int p[100001];
int find(int x) {
    if (p[x] == x) return x;
    p[x] = find(p[x]);
    return p[x];
}
bool combine(int x, int y) {
    int a = find(x), b = find(y);
    if (a == b) return false;
    p[a] = b;
    return true;
}
void kruskal() {
    sort(e + 1, e + 1 + m);
    for (int i = 1; i <= n; i++) p[i] = i;
    int ans = 0, num = 0;
    for (int i = 1; i <= m; i++) {
        if (combine(e[i].u, e[i].v)) {
            num++;
            ans = e[i].w;
        }
        if (num == n - 1) {
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    while (cin >> n >> m >> root) {
        for (int i = 1; i <= m; i++) {
            cin >> u >> v >> w;
            total++;
            e[total].u = u;
            e[total].v = v;
            e[total].w = w;
        }
        kruskal();
    }

    return 0;
}
