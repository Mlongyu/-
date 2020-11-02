#include <cstring>
#include <iostream>
using namespace std;
int  c[20],f[100001], w[1001], ww[1001];
int ans, V, cnt, N;

int main() {
    while (cin >> V >> N) {
        memset(f, 0, sizeof(f));
        memset(w, 0, sizeof(w));
        memset(c, 0, sizeof(c));
        memset(ww, 0, sizeof(ww));
        cnt = 0;
        for (int i = 1; i <= N; i++) {
            cin >> c[i] >> w[i];
        }
        for (int i = 1; i <= N; i++) {
            int t = c[i], k;
            for (k = 1; k <= t; k <<= 1) {
                cnt++;
                ww[cnt] = k * w[i];
                t -= k;
            }
            if (t > 0) {
                cnt++;
                ww[cnt] = t * w[i];
            }
        }
        N = cnt;
        for (int i = 1; i <= N; i++) {
            for (int j = V; j >= ww[i]; j--) {
                f[j] = max(f[j], f[j - ww[i]] + ww[i]);
            }
        }
        ans = f[V];
        cout << ans << endl;
    }
}
