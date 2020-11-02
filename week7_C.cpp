#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int to;
    int next;
    int weight;
};

int inf = 999999;
int n, m, t, total;
int num[100001], a[100001], dis[100001], head[100001];
queue<int> q;
bool visited[100001], flag[100001];
node edge[100001];



void dfs(int x) {
    for (int i = head[x]; i; i = edge[i].next)
        if (!flag[edge[i].to]) {
            flag[edge[i].to] = 1;
            dfs(edge[i].to);
        }
}

int main() {
    int N, x, y, z;
    cin >> N;
    for (int nn = 1; nn <= N; nn++) {
        total = 1;
        for (int i = 0; i < 100001; i++) {
            head[i] = 0;
            num[i] = 0;
            visited[i] = 0;
            flag[i] = 0;
        }
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            edge[total].next = head[x];
            edge[total].to = y;
            edge[total].weight = pow(a[y] - a[x], 3);
            head[x] = total++;
        }
        //spfa
        for (int i = 1; i <= n; i++) {
            dis[i] = inf;
        }
        dis[1] = 0;
        q.push(1);
        visited[1] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited[u] = 0;
            for (int i = head[u]; i; i = edge[i].next)
                if (dis[edge[i].to] > dis[u] + edge[i].weight) {
                    num[edge[i].to]++;
                    dis[edge[i].to] = dis[u] + edge[i].weight;
                    if (num[edge[i].to] > n) {
                        dfs(edge[i].to);
                        continue;
                    }
                    if (!visited[edge[i].to]) {
                        q.push(edge[i].to);
                        visited[edge[i].to] = 1;
                    }
                }
        }
        cout<<"Case "<<nn<<":"<<endl;
        cin >> t;
        for (int i = 1; i <= t; i++) {
            cin >> n;
            if (dis[n] < 3 || flag[n] || dis[n] == inf)
                cout << "?" << endl;
            else
                cout << dis[n] << endl;
        }
    }
    //system("pause");
    return 0;
}
