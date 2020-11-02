#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int nextNode;
    int weight;
};

int length[10001];
int maxLen, s;
vector<node> p[10001];
void DFS(int u, int fa, int len) {
    if (maxLen <= len) {
        s = u;
        maxLen = len;
    }
    int Len = p[u].size();
    for (int i = 0; i < Len; i++) {
        int v = p[u][i].nextNode;
        if (v == fa) continue;
        DFS(v, u, len + p[u][i].weight);
        length[v] = max(length[v], len + p[u][i].weight);
    }
}
int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i <= n; i++) {
            p[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            node temp;
            temp.nextNode = x;
            temp.weight = y;
            p[i].push_back(temp);
            temp.nextNode = i;
            p[x].push_back(temp);
        }
        memset(length, 0, sizeof(length));
        maxLen = 0;
        s = 0;
        DFS(1, -1, 0);
        DFS(s, -1, 0);
        DFS(s, -1, 0);
        for (int i = 1; i <= n; i++) {
            cout << length[i] << endl;
        }
    }
    return 0;
}
