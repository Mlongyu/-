#include "iostream"
using namespace std;
int a[50][50], b[50][50];
int n, m;
int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                b[i][j] = a[i][j];
            }
        }
        int ct = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (a[i][j] == a[i][j - 1]) {
                    ct++;
                    if (j == m - 1 && ct > 2) {
                        for (int p = j; p > (j - ct); p--) {
                            b[i][p] = 0;
                        }
                    }

                    continue;
                }
                if (ct > 2) {
                    for (int p = j - 1; p > (j - 1 - ct); p--) {
                        b[i][p] = 0;
                    }
                    ct = 1;
                    continue;
                }
                ct = 1;
            }
            ct = 1;
        }
        ct = 1;
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (a[i][j] == a[i-1][j ]) {
                    ct++;
                    if (i == n - 1 && ct > 2) {
                        for (int p = i; p > (i - ct); p--) {
                            b[p][j] = 0;
                        }
                    }

                    continue;
                }
                if (ct > 2) {
                    for (int p = i - 1; p > (i - 1 - ct); p--) {
                        b[p][j] = 0;
                    }
                    ct = 1;
                    continue;
                }
                ct = 1;
            }
            ct = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                cout << b[i][j] << " ";
            }
            cout << b[i][m - 1] << endl;
        }
    }
}