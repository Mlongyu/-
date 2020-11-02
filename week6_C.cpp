#include <algorithm>
#include <iostream>
using namespace std;
struct edge {
    int u, v, w;
    bool operator<(edge &e) { return w < e.w; }
};
int n, a, total;
int p[400];  //并查集
edge e[100001];

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}
bool combine(int x, int y);
void kruskal(int n);

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> a;
            total++;
            e[total].u = 0;
            e[total].v = i;
            e[total].w = a;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a;
                if (i != j) {
                    total++;
                    e[total].u = i;
                    e[total].v = j;
                    e[total].w = a;
                }
            }
        }
        sort(e + 1, e + 1 + total);
        kruskal(n);
    }
    return 0;
}
bool combine(int x, int y) {
    int a = find(x), b = find(y);
    if (a == b) return false;
    p[a] = b;
    return true;
}
void kruskal(int n) {
    for (int i = 0; i <= n; i++) p[i] = i;
    int num = 0, sum = 0;  // e[index]
    for (int i = 1; i <= total; i++) {
        if (combine(e[i].u, e[i].v))  //不在同一个集合中
        {
            num++;
            sum += e[i].w;
        }
        if (num == n) {
            cout << sum << endl;
            return;
        }
    }
}