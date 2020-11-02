#include "iostream"
using namespace std;
int a[5001], b[5001], dp[5001] ,dp1[5001][5001];
int n, m;
int main() {
    while (cin >> n >> m) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dp1[i + 1][j + 1] = dp1[i][j] + 1;
                } else {
                    dp1[i + 1][j + 1] = max(dp1[i + 1][j], dp1[i][j + 1]);
                }
            }
        }
        cout << ans << " " << dp1[n][m] << endl;
    }
}