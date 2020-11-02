#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 5 * 1e4 + 5;
const int M = 4 * 1e5 + 5;
char g[M];
int cntn[N], cntm[N];

int main() {
    int q, m, n;
    cin >> q;
    while (q--) {
        cin >> m >> n;
        memset(cntn, 0, sizeof(cntn));
        memset(cntm, 0, sizeof(cntm));
        memset(g, 0, sizeof(g));
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                cin >> g[(j - 1) * n + k];
                if (g[(j - 1) * n + k] == '*') {
                    cntn[j]++;
                    cntm[k]++;
                }
            }
        }
        int mx, ans, num;
        mx = 0;
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= n; k++) {
                if (g[(j - 1) * n + k] == '*') {
                    num = 1;
                } else if (g[(j - 1) * n + k] == '.') {
                    num = 0;
                }
                mx = max(mx, cntn[j] + cntm[k] - num);
            }
        ans = m + n - 1 - mx;
        cout << ans << endl;
    }
    return 0;
}
