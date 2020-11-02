#include <cstring>
#include <iostream>
using namespace std;

int f[10010], vis[30][10010], r[30];
int N, M, w[30], x, t;

int main() {
    while (cin >> N >> M) {
            memset(f, 0, sizeof(f));
            memset(w, 0, sizeof(w));
            memset(vis, 0, sizeof(vis));
            memset(r, 0, sizeof(r));
            for (int i = 1; i <= M; i++) {
                cin >> w[i];
            }
            for (int i = 1; i <= M; i++) {
                for (int j = N; j >= w[i]; j--) {
                    if (f[j] < f[j - w[i]] + w[i]) {
                        f[j] = f[j - w[i]] + w[i];
                        vis[i][j] = 1;
                    }
                }
            }

            for (int i = M, j = N; j >= 0 && i >= 0; i--) {
                if (vis[i][j] == 1) {
                    r[i] = 1;
                    j -= w[i];
                }
            }
            for (int i = 1; i <= M; i++) {
                if (r[i]) cout << w[i] << " ";
            }
            cout << "sum:" << f[N] << endl;
        }
}
