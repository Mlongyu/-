#include "cstring"
#include "iostream"
using namespace std;

int win[501][501];
int n, N, M, a, b, ans;
int main() {
    while (cin >> n) {
        for (int z = 0; z < n; z++) {
            memset(win, 0, sizeof(win));
            cin >> N >> M;
            for (int i = 0; i < M; i++) {
                cin >> a >> b;
                win[a - 1][b - 1] = 1;
            }
            ans = 0;
            for (int k = 0; k < N; k++) {
                for (int i = 0; i < N; i++) {
                    if (win[i][k])
                        for (int j = 0; j < N; j++) {
                            if (win[i][k] && win[k][j]) {
                                win[i][j] = 1;
                            }
                        }
                }
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if ((!win[i][j]) && (!win[j][i]) && i != j) {
                        ans++;
                    }
                    // cout<<win[i][j]<<" ";
                }
                // cout<<endl;
            }

            cout << ans / 2 << endl;
        }
    }
    return 0;
}